#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int> &arr, int key, int &comparisons) {
    int low = 0;
    int high = arr.size() - 1;

    while (low <= high) {
        int mid = (low + high) / 2;
        comparisons++;

        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}

int main() {
     int T,key;
    cout<<"enter the no of test cases  ";
    cin >> T;

    vector<int> arr;

    while (T--) {
     int n;
        cout<<"enter no of element  ";
        cin >> n;

        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            arr.push_back(x);
        }


    cout << "Enter key element: ";
    cin >> key;

    int comparisons = 0;

    int result = binarySearch(arr, key, comparisons);

    if (result != -1)
        cout << "Element found at position " << result + 1 << endl;
    else
        cout << "Element not found" << endl;

    cout << "Total comparisons = " << comparisons << endl;
    }

    return 0;
}