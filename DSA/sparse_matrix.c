#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int row;
    int col;
    int value;
    struct Node *next;
};

void displaySparseMatrix(struct Node *head)
{
    struct Node *current = head;

    printf("Row\tColumn\tValue\n");
    while (current != NULL)
    {
        printf("%d\t%d\t%d\n", current->row, current->col, current->value);
        current = current->next;
    }
}

int main()
{
    struct Node *matrixHead = (struct Node *)malloc(sizeof(struct Node));
    matrixHead->row = 0;
    matrixHead->col = 2;
    matrixHead->value = 10;

    struct Node *matrixNode1 = (struct Node *)malloc(sizeof(struct Node));
    matrixNode1->row = 1;
    matrixNode1->col = 1;
    matrixNode1->value = 20;

    struct Node *matrixNode2 = (struct Node *)malloc(sizeof(struct Node));
    matrixNode2->row = 2;
    matrixNode2->col = 0;
    matrixNode2->value = 30;

    matrixHead->next = matrixNode1;
    matrixNode1->next = matrixNode2;
    matrixNode2->next = NULL;

    displaySparseMatrix(matrixHead);

    free(matrixHead);
    free(matrixNode1);
    free(matrixNode2);

    return 0;
}