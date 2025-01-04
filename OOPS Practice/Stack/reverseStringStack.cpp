#include <iostream>
#include <stack>
#include <string>
using namespace std;

string reverseString(string str) {
    if (str.length() == 1) {
        return str;
    }

    stack <char> ch;

    for (char stringCharacter : str) {
        ch.push(stringCharacter);
    }

    string reversedString = "";

    while (!ch.empty()) {
        reversedString += ch.top();
        ch.pop();
    }

    return reversedString;
}

int main() {
    string stringToReverse;
    cout << "Enter the string you want to reverse : ";
    cin >> stringToReverse;
    cout << endl;

    cout << "The original string was : " << stringToReverse << " & it's reversed version is : " << reverseString(stringToReverse) << endl;

    return 0;
}