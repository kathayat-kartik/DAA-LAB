#include <iostream>
#include <vector>
#include <cmath> 
using namespace std;
bool jumpSearch(const vector<int>& arr, int key, int& comparisons, int& position) {
    int n = arr.size();
    int step = sqrt(n); 
    int prev = 0;

    comparisons = 0;
    while (arr[min(step, n) - 1] < key) {
        comparisons++;
        prev = step;
        step += sqrt(n);
        if (prev >= n) 
            return false;
    }

    for (int i = prev; i < min(step, n); i++) {
        comparisons++;
        if (arr[i] == key) {
            position = i + 1; 
            return true;
        }
    }

    return false;
}

int main() {
    int testCases;
    cout << "No of test cases: ";
    cin >> testCases;

    while (testCases--) {
        int n;
        cout << "No of elements: ";
        cin >> n;

        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        int key;
        cout << "Element to search: ";
        cin >> key;

        int comparisons = 0;
        int position = -1;

        bool found = jumpSearch(arr, key, comparisons, position);

        if (found)
            cout << "Present " << position << endl;
        else
            cout << "Not Present " << comparisons << endl;
    }

    return 0;
}