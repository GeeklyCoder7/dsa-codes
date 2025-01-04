#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int marks[] = {89, 83, 81, 67, 36, 83, 1, 101};
    int size = sizeof(marks) / sizeof(marks[0]);
    int smalllest = INT_MAX;
    int largest = INT_MIN;

    for(int i = 0; i < size; i++) {
        if (marks[i] < smalllest)
        {
            smalllest = marks[i];
        }

        if (marks[i] > largest)
        {
            largest = marks[i];
        }
        
        
    }

    cout << "The smallest element is : " << smalllest << endl;
    cout << "The largest element is : " << largest << endl;

    return 0;
}