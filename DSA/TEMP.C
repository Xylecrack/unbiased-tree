#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define MIN_DEGREE 2

typedef struct BTreeNode
{
    int *keys;
    int t;
    struct BTreeNode **C;
    int n;
    bool leaf;
} BTreeNode;

typedef struct BTree
{
    BTreeNode *root;
    int t;
} BTree;

BTreeNode *createNode(int t, bool leaf)
{
    BTreeNode *newNode = (BTreeNode *)malloc(sizeof(BTreeNode));
    newNode->t = t;
    newNode->leaf = leaf;
    newNode->keys = (int *)malloc((2 * t - 1) * sizeof(int));
    newNode->C = (BTreeNode **)malloc((2 * t) * sizeof(BTreeNode *));
    newNode->n = 0;
    return newNode;
}

void splitChild(BTreeNode *x, int i, BTreeNode *y)
{
    int t = y->t;
    BTreeNode *z = createNode(t, y->leaf);
    z->n = t - 1;

    for (int j = 0; j < t - 1; j++)
        z->keys[j] = y->keys[j + t];

    if (!y->leaf)
    {
        for (int j = 0; j < t; j++)
            z->C[j] = y->C[j + t];
    }

    y->n = t - 1;

    for (int j = x->n; j >= i + 1; j--)
        x->C[j + 1] = x->C[j];

    x->C[i + 1] = z;

    for (int j = x->n - 1; j >= i; j--)
        x->keys[j + 1] = x->keys[j];

    x->keys[i] = y->keys[t - 1];
    x->n = x->n + 1;
}

void insertNonFull(BTreeNode *x, int k)
{
    int i = x->n - 1;

    if (x->leaf)
    {
        while (i >= 0 && x->keys[i] > k)
        {
            x->keys[i + 1] = x->keys[i];
            i--;
        }

        x->keys[i + 1] = k;
        x->n = x->n + 1;
    }
    else
    {
        while (i >= 0 && x->keys[i] > k)
            i--;

        if (x->C[i + 1]->n == 2 * x->t - 1)
        {
            splitChild(x, i + 1, x->C[i + 1]);

            if (x->keys[i + 1] < k)
                i++;
        }
        insertNonFull(x->C[i + 1], k);
    }
}

void insert(BTree *tree, int k)
{
    if (tree->root == NULL)
    {
        tree->root = createNode(tree->t, true);
        tree->root->keys[0] = k;
        tree->root->n = 1;
    }
    else
    {
        if (tree->root->n == 2 * tree->t - 1)
        {
            BTreeNode *s = createNode(tree->t, false);
            s->C[0] = tree->root;
            splitChild(s, 0, tree->root);
            int i = 0;
            if (s->keys[0] < k)
                i++;
            insertNonFull(s->C[i], k);
            tree->root = s;
        }
        else
        {
            insertNonFull(tree->root, k);
        }
    }
}

void rangeSearch(BTreeNode *node, int low, int high)
{
    int i = 0;

    while (i < node->n && node->keys[i] < low)
        i++;

    while (i < node->n && node->keys[i] <= high)
    {
        if (!node->leaf)
            rangeSearch(node->C[i], low, high);
        printf("%d ", node->keys[i]);
        i++;
    }

    if (!node->leaf)
        rangeSearch(node->C[i], low, high);
}

int main()
{
    BTree tree;
    tree.root = NULL;
    tree.t = MIN_DEGREE;

    int keys[] = {20, 5, 1, 10, 15, 30, 25, 40, 35, 50};
    int n = sizeof(keys) / sizeof(keys[0]);

    for (int i = 0; i < n; i++)
    {
        insert(&tree, keys[i]);
    }

    int low = 10, high = 35;
    printf("Keys in range [%d, %d]:\n", low, high);
    rangeSearch(tree.root, low, high);

    return 0;
}
