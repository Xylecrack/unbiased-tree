//Extend the BigInt operations to include subtraction, multiplication, and division.

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAX_DIGITS 1000

class BigInt {
private:
    char digits[MAX_DIGITS];
    int length;
    bool isNegative;

    void removeLeadingZeros() {
        int i = 0;
        while (i < length - 1 && digits[i] == '0') {
            i++;
        }
        if (i > 0) {
            length -= i;
            for (int j = 0; j < length; j++) {
                digits[j] = digits[j + i];
            }
        }
    }

public:
        BigInt(string num) {
        isNegative = (num[0] == '-');
        length = num.length() - isNegative;
        for (int i = 0; i < length; i++) {
            digits[i] = num[i + isNegative];
        }
        removeLeadingZeros();
    }

    void print() const {
        if (isNegative) cout << "-";
        for (int i = 0; i < length; i++) {
            cout << digits[i];
        }
        cout << endl;
    }

    BigInt operator+(const BigInt& other) {
        string result = "";
        int carry = 0, sum;
        int i = length - 1, j = other.length - 1;

        while (i >= 0 || j >= 0 || carry) {
            int digit1 = (i >= 0) ? digits[i] - '0' : 0;
            int digit2 = (j >= 0) ? other.digits[j] - '0' : 0;
            sum = digit1 + digit2 + carry;
            carry = sum / 10;
            result += (sum % 10) + '0';
            i--; j--;
        }
        reverse(result.begin(), result.end());
        return BigInt(result);
    }

    BigInt operator-(const BigInt& other) {
        string result = "";
        int borrow = 0;

        int i = length - 1, j = other.length - 1;
        while (i >= 0) {
            int digit1 = digits[i] - '0';
            int digit2 = (j >= 0) ? other.digits[j] - '0' : 0;

            if (digit1 < digit2 + borrow) {
                digit1 += 10;
                result += (digit1 - digit2 - borrow) + '0';
                borrow = 1;
            } else {
                result += (digit1 - digit2 - borrow) + '0';
                borrow = 0;
            }
            i--; j--;
        }

        reverse(result.begin(), result.end());
        return BigInt(result);
    }

    BigInt operator*(const BigInt& other) {
        int result[MAX_DIGITS] = {0};
        int len1 = length, len2 = other.length;

        for (int i = len1 - 1; i >= 0; i--) {
            for (int j = len2 - 1; j >= 0; j--) {
                int mul = (digits[i] - '0') * (other.digits[j] - '0');
                result[i + j + 1] += mul;
                result[i + j] += result[i + j + 1] / 10;
                result[i + j + 1] %= 10;
            }
        }

        string product = "";
        for (int i = 0; i < len1 + len2; i++) {
            if (!(product.empty() && result[i] == 0)) {
                product += result[i] + '0';
            }
        }

        return (product.empty()) ? BigInt("0") : BigInt(product);
    }

    BigInt operator/(const BigInt& other) {
        if (other == BigInt("0")) {
            throw runtime_error("Division by zero error");
        }

        BigInt quotient("0"), remainder("0");

        for (int i = 0; i < length; i++) {
            remainder = remainder * BigInt("10") + BigInt(string(1, digits[i]));
            int count = 0;
            while (remainder >= other) {
                remainder = remainder - other;
                count++;
            }
            quotient = quotient * BigInt("10") + BigInt(to_string(count));
        }

        return quotient;
    }

    bool operator<(const BigInt& other) const {
        if (length != other.length) return length < other.length;
        for (int i = 0; i < length; i++) {
            if (digits[i] != other.digits[i]) {
                return digits[i] < other.digits[i];
            }
        }
        return false;
    }

    bool operator>=(const BigInt& other) const {
        return !(*this < other);
    }

    bool operator==(const BigInt& other) const {
        return length == other.length && strcmp(digits, other.digits) == 0;
    }
};

int main() {
    BigInt num1("9876543210");
    BigInt num2("1234567890");

    cout << "Num1: "; num1.print();
    cout << "Num2: "; num2.print();

    cout << "Addition: "; (num1 + num2).print();
    cout << "Subtraction: "; (num1 - num2).print();
    cout << "Multiplication: "; (num1 * num2).print();
    cout << "Division: "; (num1 / num2).print();

    return 0;
}
