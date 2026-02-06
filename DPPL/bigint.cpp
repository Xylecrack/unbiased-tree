#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
    int digit;
    struct Node *next;
} Node;

typedef struct
{
    Node *head;
} BigIntLL;

BigIntLL initBigInt(const char *num)
{
    BigIntLL bigInt;
    bigInt.head = NULL;
    Node *prev = NULL;

    for (int i = 0; i < strlen(num); i++)
    {
        Node *newNode = (Node *)malloc(sizeof(Node));
        newNode->digit = num[i] - '0';
        newNode->next = NULL;

        if (prev)
            prev->next = newNode;
        else
            bigInt.head = newNode;
        prev = newNode;
    }

    return bigInt;
}

int compareBigInt(BigIntLL a, BigIntLL b)
{
    Node *n1 = a.head, *n2 = b.head;
    int len1 = 0, len2 = 0;

    while (n1)
    {
        len1++;
        n1 = n1->next;
    }
    while (n2)
    {
        len2++;
        n2 = n2->next;
    }

    if (len1 > len2)
        return 1;
    if (len1 < len2)
        return -1;

    char *num1 = (char *)malloc(len1 * sizeof(char));
    char *num2 = (char *)malloc(len2 * sizeof(char));
    n1 = a.head;
    n2 = b.head;

    for (int i = 0; i < len1; i++, n1 = n1->next, n2 = n2->next)
    {
        num1[len1 - i - 1] = n1->digit;
        num2[len2 - i - 1] = n2->digit;
    }
    int result = strcmp(num1, num2);
    free(num1);
    free(num2);
    return result;
}

BigIntLL addBigInt(BigIntLL a, BigIntLL b)
{
    BigIntLL result;
    result.head = NULL;
    Node *n1 = a.head, *n2 = b.head, *prev = NULL;
    int carry = 0;

    while (n1 || n2 || carry)
    {
        int d1 = (n1) ? n1->digit : 0;
        int d2 = (n2) ? n2->digit : 0;
        int sum = d1 + d2 + carry;
        carry = sum / 10;

        Node *newNode = (Node *)malloc(sizeof(Node));
        newNode->digit = sum % 10;
        newNode->next = NULL;

        if (prev)
            prev->next = newNode;
        else
            result.head = newNode;
        prev = newNode;

        if (n1)
            n1 = n1->next;
        if (n2)
            n2 = n2->next;
    }

    return result;
}

BigIntLL subtractBigInt(BigIntLL a, BigIntLL b)
{
    if (compareBigInt(a, b) < 0)
    {
        printf("Error: Negative result not supported\n");
        exit(1);
    }

    BigIntLL result;
    result.head = NULL;
    Node *n1 = a.head, *n2 = b.head, *prev = NULL;
    int borrow = 0;

    while (n1)
    {
        int d1 = n1->digit - borrow;
        int d2 = (n2) ? n2->digit : 0;

        if (d1 < d2)
        {
            d1 += 10;
            borrow = 1;
        }
        else
        {
            borrow = 0;
        }

        Node *newNode = (Node *)malloc(sizeof(Node));
        newNode->digit = d1 - d2;
        newNode->next = NULL;

        if (prev)
            prev->next = newNode;
        else
            result.head = newNode;
        prev = newNode;

        n1 = n1->next;
        if (n2)
            n2 = n2->next;
    }

    return result;
}

BigIntLL multiplyBigInt(BigIntLL a, BigIntLL b)
{
    BigIntLL result = initBigInt("0");

    Node *n1 = a.head;
    int shift = 0;

    while (n1)
    {
        BigIntLL temp;
        temp.head = NULL;
        Node *prev = NULL;
        int carry = 0;
        Node *n2 = b.head;

        for (int i = 0; i < shift; i++)
        {
            Node *newNode = (Node *)malloc(sizeof(Node));
            newNode->digit = 0;
            newNode->next = temp.head;
            temp.head = newNode;
        }

        while (n2)
        {
            int prod = (n1->digit * n2->digit) + carry;
            carry = prod / 10;

            Node *newNode = (Node *)malloc(sizeof(Node));
            newNode->digit = prod % 10;
            newNode->next = NULL;

            if (prev)
                prev->next = newNode;
            else
                temp.head = newNode;
            prev = newNode;

            n2 = n2->next;
        }

        if (carry)
        {
            Node *newNode = (Node *)malloc(sizeof(Node));
            newNode->digit = carry;
            newNode->next = NULL;
            prev->next = newNode;
        }

        result = addBigInt(result, temp);
        shift++;
        n1 = n1->next;
    }

    return result;
}

void printBigInt(BigIntLL bigInt)
{
    Node *temp = bigInt.head;
    if (!temp)
    {
        printf("0\n");
        return;
    }

    char stack[1000];
    int top = 0;

    while (temp)
    {
        stack[top++] = temp->digit + '0';
        temp = temp->next;
    }

    while (top > 0)
    {
        printf("%c", stack[--top]);
    }
    printf("\n");
}

void freeBigInt(BigIntLL *bigInt)
{
    Node *temp;
    while (bigInt->head)
    {
        temp = bigInt->head;
        bigInt->head = bigInt->head->next;
        free(temp);
    }
}

int main()
{
    BigIntLL num1 = initBigInt("23");
    BigIntLL num2 = initBigInt("25");

    printf("Num1: ");
    printBigInt(num1);
    printf("Num2: ");
    printBigInt(num2);

    BigIntLL sum = addBigInt(num1, num2);
    printf("Sum: ");
    printBigInt(sum);

    BigIntLL diff = subtractBigInt(num2, num1);
    printf("Difference: ");
    printBigInt(diff);

    BigIntLL product = multiplyBigInt(num1, num2);
    printf("Product: ");
    printBigInt(product);

    freeBigInt(&num1);
    freeBigInt(&num2);
    freeBigInt(&sum);
    freeBigInt(&diff);
    freeBigInt(&product);

    return 0;
}