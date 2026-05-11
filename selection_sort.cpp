
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[100];
    cout << "Enter elements:\n";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Selection Sort
    for(int i = 0; i < n-1; i++) {
        int minIndex = i;

        for(int j = i+1; j < n; j++) {
            if(arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        // Swap
        swap(arr[i], arr[minIndex]);
    }

    cout << "Sorted array:\n";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}