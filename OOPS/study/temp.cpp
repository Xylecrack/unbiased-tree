#include <iostream>
using namespace std;

class MyClass {
public:
    // Constructor
    MyClass() {
        // Allocate some resource
        data = new int[10];
        cout << "Constructor: Resource allocated." << endl;
    }

    // Destructor
    ~MyClass() {
        // Release the allocated resource
        delete[] data;
        cout << "Destructor: Resource deallocated." << endl;
    }

private:
    int* data; // Pointer to an array of integers
};

int main() {
    // Create an instance of MyClass
    MyClass obj;

    // Rest of the code

    return 0;
}