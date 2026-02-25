#include <bits/stdc++.h>
using namespace std;
void findMaxOcc(vector<char>& arr) {
    vector<int> count(26, 0);

    for (char ch : arr) {
        count[ch - 'a']++;
    }

    int maxCount = 0;
    char result = '\0';

    for (int i = 0; i < 26; i++) {
        if (count[i] > maxCount) {
            maxCount = count[i];
            result = char(i + 'a');
        }
    }

    if (maxCount <= 1) {
        cout << "No Duplicates Present\n";
    } else {
        cout << result << " " << maxCount << "\n";
    }
}

int main() {
    int T;
    cout<<"enter the no of test cases ";
    cin >> T;

    vector<char> arr;   // declared outside loop

    while (T--) {
        int n;
        cout<<"enter the size of array"<<endl;
        cin >> n;

         char ch;
    for (int i = 0; i < n; i++) {
        cin >> ch;
        arr.push_back(ch);
    }
        findMaxOcc(arr);

        arr.clear();   // clear for next test case
    }

    return 0;
}