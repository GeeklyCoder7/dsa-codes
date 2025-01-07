#include <iostream>
using namespace std;

class Complex
{
public:
    // Real and Imaginary parts
    int real, imag;

    // Constructor to initialize the complex number
    Complex(int r, int i) : real(r), imag(i) {}

    // Overloading the '+' operator to add two Complex numbers
    Complex operator+(const Complex &c)
    {
        return Complex(real + c.real, imag + c.imag);
    }

    // Function to display the complex number
    void display()
    {
        cout << real << " + " << imag << "i" << endl;
    }
};

int main()
{
    int real1, imag1, real2, imag2;

    // Taking user input for the first complex number
    cout << "Enter real part of first complex number: ";
    cin >> real1;
    cout << "Enter imaginary part of first complex number: ";
    cin >> imag1;

    // Creating the first complex number
    Complex c1(real1, imag1);

    // Taking user input for the second complex number
    cout << "Enter real part of second complex number: ";
    cin >> real2;
    cout << "Enter imaginary part of second complex number: ";
    cin >> imag2;

    // Creating the second complex number
    Complex c2(real2, imag2);

    // Using overloaded '+' operator to add complex numbers
    Complex c3 = c1 + c2;

    // Display the result
    cout << "Sum of complex numbers: ";
    c3.display();

    return 0;
}