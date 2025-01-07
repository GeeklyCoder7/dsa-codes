#include <iostream>
using namespace std;

class Example {
private:
    int* data; // Pointer to an integer

public:
    // Constructor
    Example(int value) {
        data = new int(value); // Dynamically allocate memory
    }

    // Shallow Copy Constructor
    Example(const Example& obj) {
        data = obj.data; // Copy the pointer (not the actual data)
        cout << "Shallow Copy Constructor Called!" << endl;
    }

    // Display function
    void display() {
        cout << "Data: " << *data << endl;
    }

    // Destructor
    ~Example() {
        delete data; // Free allocated memory
        cout << "Destructor Called!" << endl;
    }
};

int main() {
    Example obj1(10); // Create an object
    cout << "Original Object: ";
    obj1.display();

    Example obj2 = obj1; // Create a copy (shallow copy)
    cout << "Copied Object: ";
    obj2.display();

    return 0; // Both destructors will try to delete the same memory, leading to issues
}
