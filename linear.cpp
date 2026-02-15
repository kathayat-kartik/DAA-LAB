#include <iostream>
#include <vector>
using namespace std;
bool linearSearch(const vector<int>& arr, int key, int& comparisons) {
    comparisons = 0;

    for (int value : arr) {
        comparisons++;
        if (value == key) {
            return true;
        }
    }
    return false;
}

int main() {
    int testCases;
    cout<<"enter the the no of test cases"<<endl;
    cin >> testCases;

    while (testCases--) {
        int n;
        cout<<"enter the size of array";
        cin >> n;

        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        int key;
        cout<<"enter the element to search";
        cin >> key;

        int comparisons = 0;
        bool isPresent = linearSearch(arr, key, comparisons);

        if (isPresent) {
            cout << "Present " << comparisons << endl;
        } else {
            cout << "Not Present " << comparisons << endl;
        }
    }

    return 0;
}