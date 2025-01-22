#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void info()
{
    printf("******************************************************\n");
    printf("Name: Dhruva Narayan K\n");
    printf("BT ID.: BT23CSE016\n");
    time_t currentTime;
    time(&currentTime);
    struct tm *localTime = localtime(&currentTime);
    printf("Current local time: %s", asctime(localTime));
}

struct node
{
    int coef;
    int exp;
    struct node *next;
};

struct node *insert(struct node *head, int ex, int co)
{
    struct node *temp;
    struct node *newp = malloc(sizeof(struct node));
    newp->exp = ex;
    newp->coef = co;
    newp->next = NULL;
    if (head == NULL || ex > head->exp)
    {
        newp->next = head;
        head = newp;
    }
    else
    {
        temp = head;
        while (temp->next != NULL && temp->next->exp >= ex)
        {
            temp = temp->next;
        }
        newp->next = temp->next;
        temp->next = newp;
    }
    return head;
}

struct node *create(struct node *head)
{
    int n, exp, coef;
    printf("Enter the number of terms in the first polynomial: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("Enter the exponent and coefficient of term %d: ", i + 1);
        scanf("%d %d", &exp, &coef);
        head = insert(head, exp, coef);
    }
    return head;
}
void add(struct node *head)
{
    int n, exp, coef;
    struct node *temp;
    printf("Enter the number of terms in the second polynomial: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("Enter the exponent and coefficient of term %d: ", i + 1);
        scanf("%d %d", &exp, &coef);
        temp = head;
        while (temp != NULL && temp->exp != exp)
        {
            temp = temp->next;
        }
        if (temp != NULL)
        {
            temp->coef += coef;
        }
        else
        {
            head = insert(head, exp, coef);
        }
    }
    printf("The sum of the two polynomials is: ");
    display(head);
}

void display(struct node *head)
{
    struct node *temp = head;
    while (temp != NULL)
    {
        printf("%dx^%d", temp->coef, temp->exp);
        temp = temp->next;
        if (temp != NULL)
        {
            printf(" + ");
        }
    }
    printf("\n");
}

int main()
{
    struct node *head = NULL;
    head = create(head);
    printf("The first polynomial is: ");
    display(head);
    add(head);
    info();
    return 0;
}