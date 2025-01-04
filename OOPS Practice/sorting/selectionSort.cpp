#include <iostream>
using namespace std;

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void selectionSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;
        for(int j = i + 1; j < size; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[minIndex], arr[i]);
    }
}

int main() {
    int arr[] = {65, 21, 3, 12, 10, 8, 71};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Before sorting : " << endl;
    printArray(arr, size);

    cout << "After sorting : " << endl;
    selectionSort(arr, size);
    printArray(arr, size);

    return 0;
}