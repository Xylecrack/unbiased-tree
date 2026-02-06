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
    int n;
    int exp, coef;

    printf("Enter the number of terms in the polynomial: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("Enter the exponent and coefficient of term %d: ", i + 1);
        scanf("%d %d", &exp, &coef);
        head = insert(head, exp, coef);
    }
    return head;
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
            printf("+");
        }
    }
    printf("\n");
}
void poly_mul(struct node *head1, struct node *head2)
{
    struct node *temp1 = head1;
    struct node *temp2 = head2;
    struct node *head3 = NULL;

    while (temp1 != NULL)
    {
        temp2 = head2;
        while (temp2 != NULL)
        {
            head3 = insert(head3, temp1->exp + temp2->exp, temp1->coef * temp2->coef);
            temp2 = temp2->next;
        }
        temp1 = temp1->next;
    }

    struct node *temp3 = head3;
    while (temp3 != NULL && temp3->next != NULL)
    {
        struct node *current = temp3;
        while (current->next != NULL)
        {
            if (temp3->exp == current->next->exp)
            {
                temp3->coef += current->next->coef;
                struct node *temp4 = current->next;
                current->next = current->next->next;
                free(temp4);
            }
            else
            {
                current = current->next;
            }
        }
        temp3 = temp3->next;
    }

    display(head3);
}

int main()
{
    struct node *head1 = NULL;
    struct node *head2 = NULL;
    head1 = create(head1);
    head2 = create(head2);
    printf("The first polynomial is: ");
    display(head1);
    printf("The second polynomial is: ");
    display(head2);
    printf("The product of the two polynomials is: ");
    poly_mul(head1, head2);
    info();
    return 0;
}