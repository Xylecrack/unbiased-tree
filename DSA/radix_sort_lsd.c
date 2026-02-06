#include <stdio.h>
#include <stdlib.h>
#define null NULL

struct node
{
    int num;
    struct node *next;
};

int max_num(struct node *head)
{
    int max = head->num;

    struct node *curr = head->next;

    while (curr != null)
    {
        if (curr->num > max)
        {
            max = curr->num;
        }
        curr = curr->next;
    }
    return max;
}

int get_digit(int num, int exp)
{
    return (num / exp) % 10;
}

struct node *counting_sort(struct node *head, int exp)
{
    struct node *bucket[10] = {null};
    struct node *tails[10] = {null};

    struct node *curr = head;
    while (curr != null)
    {
        int digit = get_digit(curr->num, exp);
        if (bucket[digit] == null)
        {
            bucket[digit] = curr;
            tails[digit] = curr;
        }
        else
        {
            tails[digit]->next = curr;
            tails[digit] = curr;
        }
        curr = curr->next;
    }
    struct node *new_head = null;
    struct node *new_tail = null;

    for (int i = 0; i < 10; i++)
    {
        if (bucket[i] != null)
        {
            if (new_head == null)
            {
                new_head = bucket[i];
                new_tail = tails[i];
            }
            else
            {
                new_tail->next = bucket[i];
                new_tail = tails[i];
            }
        }
    }
    new_tail->next = null;
    return new_head;
}

struct node *radix_sort(struct node *head)
{
    int max = max_num(head);
    int exp = 1;

    while (max / exp > 0)
    {
        head = counting_sort(head, exp);
        exp *= 10;
    }
    return head;
}

void printlist(struct node *head)
{
    while (head != null)
    {
        printf("%d ", head->num);
        head = head->next;
    }
    printf("\n");
}

void insert(struct node **head, int num)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->num = num;
    new_node->next = *head;
    *head = new_node;
}

int main()
{
    struct node *head = null;
    insert(&head, 170);
    insert(&head, 54);
    insert(&head, 91);
    insert(&head, 90);
    insert(&head, 112);
    insert(&head, 34);
    insert(&head, 2);
    insert(&head, 79);
    insert(&head, 0);
    insert(&head, 100);
    printf("Unsorted list: ");
    printlist(head);

    head = radix_sort(head);
    printf("Sorted list: ");
    printlist(head);
    return 0;
}
