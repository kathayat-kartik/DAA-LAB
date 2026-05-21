#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Function to find pair with given sum
void findPair(vector<int>& arr, int key) {
    unordered_map<int, int> freq;

    // Build frequency map
    for (int i = 0; i < arr.size(); i++) {
        freq[arr[i]]++;
    }

    bool found = false;

    // Check for valid pair
    for (int i = 0; i < arr.size(); i++) {
        int x = arr[i];
        int complement = key - x;

        // Reduce frequency temporarily
        freq[x]--;

        if (freq[complement] > 0) {
            cout << x << " " << complement << endl;
            found = true;
            break;
        }

        // Restore frequency
        freq[x]++;
    }

    if (!found) {
        cout << "No Such Elements Exist" << endl;
    }
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        vector<int> arr(n);

        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        int key;
        cin >> key;

        // Function call
        findPair(arr, key);
    }

    return 0;
}