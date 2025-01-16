package javalab.abc;

public class Factorial {

    // Recursive method to calculate factorial
    public static int factorial(int n) {
        if (n == 0 || n == 1) {
            return 1;
        }
        return n * factorial(n - 1);
    }

    public static void main(String[] args) {
        int number = 5;  // Example number for factorial
        int result = factorial(number);
        System.out.println("The factorial of " + number + " is: " + result);
    }
}
