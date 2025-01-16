#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void info() {
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
void add(struct node *head1, struct node *head2)
{
    struct node *temp1 = head1;
    struct node *temp2 = head2;
    struct node *head3 = NULL;
    while (temp1 != NULL && temp2 != NULL)
    {
        if (temp1->exp == temp2->exp)
        {
            head3 = insert(head3, temp1->exp, temp1->coef + temp2->coef);
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        else if (temp1->exp > temp2->exp)
        {
            head3 = insert(head3, temp1->exp, temp1->coef);
            temp1 = temp1->next;
        }
        else
        {
            head3 = insert(head3, temp2->exp, temp2->coef);
            temp2 = temp2->next;
        }
    }
    while (temp1 != NULL)
    {
        head3 = insert(head3, temp1->exp, temp1->coef);
        temp1 = temp1->next;
    }
    while (temp2 != NULL)
    {
        head3 = insert(head3, temp2->exp, temp2->coef);
        temp2 = temp2->next;
    }
    display(head3);
}
int main()
{
    struct node *head1 = NULL;
    struct node *head2 = NULL;
    printf("Enter the first polynomial \n");
    printf("-------------------------- \n");
    head1 = create(head1);
    printf("Enter the second polynomial \n");
    printf("-------------------------- \n");
    head2 = create(head2);
    printf("The first polynomial is: ");
    display(head1);
    printf("The second polynomial is: ");
    display(head2);
    printf("The sum of the two polynomials is: ");
    add(head1, head2);
    info();
    return 0;
}