#include <stdio.h>
#include <stdlib.h>

struct node
{
    int num;
    struct node *link;
};

int getmax(struct node *head)
{
    int max = abs(head->num);
    struct node *current = head->link;
    while (current != NULL)
    {
        if (abs(current->num) > max)
        {
            max = abs(current->num);
        }
        current = current->link;
    }
    return max;
}

int getdigit(int number, int place)
{
    return (abs(number) / place) % 10;
}

void insertEnd(struct node **head, int data)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->num = data;
    new_node->link = NULL;

    if (*head == NULL)
    {
        *head = new_node;
    }
    else
    {
        struct node *current = *head;
        while (current->link != NULL)
        {
            current = current->link;
        }
        current->link = new_node;
    }
}

void insert(struct node **head, struct node *new_node)
{
    if (*head == NULL)
    {
        *head = new_node;
    }
    else
    {
        struct node *current = *head;
        while (current->link != NULL)
        {
            current = current->link;
        }
        current->link = new_node;
    }
}

void radixSortPositive(struct node **head)
{
    struct node *buckets[10];
    struct node *current;
    int max = getmax(*head);
    int place = 1;

    while (max / place > 0)
    {
        for (int i = 0; i < 10; i++)
        {
            buckets[i] = NULL;
        }

        current = *head;
        while (current != NULL)
        {
            int digit = getdigit(current->num, place);
            struct node *link = current->link;
            current->link = NULL;
            insert(&buckets[digit], current);
            current = link;
        }

        *head = NULL;
        for (int i = 0; i < 10; i++)
        {
            if (buckets[i] != NULL)
            {
                if (*head == NULL)
                {
                    *head = buckets[i];
                }
                else
                {
                    insert(head, buckets[i]);
                }
            }
        }

        place *= 10;
    }
}

void radixSortNegative(struct node **head)
{
    struct node *buckets[10];
    struct node *current;
    int max = getmax(*head);
    int place = 1;

    while (max / place > 0)
    {
        for (int i = 0; i < 10; i++)
        {
            buckets[i] = NULL;
        }

        current = *head;
        while (current != NULL)
        {
            int digit = getdigit(current->num, place);
            struct node *link = current->link;
            current->link = NULL;
            insert(&buckets[digit], current);
            current = link;
        }

        *head = NULL;
        for (int i = 9; i >= 0; i--)
        {
            if (buckets[i] != NULL)
            {
                if (*head == NULL)
                {
                    *head = buckets[i];
                }
                else
                {
                    insert(head, buckets[i]);
                }
            }
        }

        place *= 10;
    }
}

void mergeLists(struct node **head, struct node *negativeList, struct node *positiveList)
{
    if (negativeList != NULL)
    {
        *head = negativeList;
        while (negativeList->link != NULL)
        {
            negativeList = negativeList->link;
        }
        negativeList->link = positiveList;
    }
    else
    {
        *head = positiveList;
    }
}

void radixSort(struct node **head)
{
    struct node *negativeList = NULL;
    struct node *positiveList = NULL;
    struct node *current = *head;

    while (current != NULL)
    {
        struct node *next = current->link;
        current->link = NULL;
        if (current->num < 0)
        {
            insert(&negativeList, current);
        }
        else
        {
            insert(&positiveList, current);
        }
        current = next;
    }

    if (negativeList != NULL)
    {
        radixSortNegative(&negativeList);
    }
    if (positiveList != NULL)
    {
        radixSortPositive(&positiveList);
    }

    mergeLists(head, negativeList, positiveList);
}

struct node *newNode(int data)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->num = data;
    new_node->link = NULL;
    return new_node;
}

void printList(struct node *head)
{
    while (head != NULL)
    {
        printf("%d ", head->num);
        head = head->link;
    }
    printf("\n");
}

int main()
{
    struct node *head = NULL;

    insertEnd(&head, -10);
    insertEnd(&head, 145);
    insertEnd(&head, -75);
    insertEnd(&head, 90);
    insertEnd(&head, -101);
    insertEnd(&head, 34);
    insertEnd(&head, 12);
    insertEnd(&head, -22);

    printf("Unsorted List: ");
    printList(head);

    radixSort(&head);

    printf("Sorted List: ");
    printList(head);
    return 0;
}