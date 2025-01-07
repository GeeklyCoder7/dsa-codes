#include <iostream>
using namespace std;

class Box {
    private :
        int length;

    public :
        Box() {
            length = 0;
        }

        void setLength(int length) {
            length = length;
        }

        friend void displayLength(Box b);
};

void displayLength(Box b) {
    cout << "The length of the box is : " << b.length << endl;
}

int main() {
    Box b;
    displayLength(b);

    b.setLength(10);
    displayLength(b);

    return 0;
}