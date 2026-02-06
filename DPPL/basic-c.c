#include <stdio.h>

// Define a macro to control conditional compilation
#define DEBUG

int main()
{
    int a, b, sum = 0;

    // Read two numbers from the user
    printf("Enter two integers: ");
    scanf("%d %d", &a, &b);

    // Calculate the addition of a and b
    sum = a + b;

    // Conditionally compile debug information
    #ifdef DEBUG
        printf("Debug: a = %d, b = %d\n", a, b);
    #endif


    printf("Sum: %d\n", sum);

    return 0;
}