#include <iostream>
#include <string>
using namespace std;

class Box {
    private :
        int length;

    public :
        Box(int l) {
            length = l;
        }

        int getLength() {
            return length;
        }

        friend class BoxOperations;
};

class BoxOperations {
    public :
        void doubleLength(Box &b) {
            b.length = b.length * 2;
        }
};

int main() {
    Box b(10);
    cout << "Original length : " << b.getLength() << endl;

    BoxOperations b1;
    b1.doubleLength(b);

    cout << "Doubled length : " << b.getLength() << endl;

    return 0;
}