#include<iostream>
#include<vector>
using namespace std;

void findSequence(vector<int> &arr, int n)
{
    bool found = false;

    for(int k = n-1; k >= 2; k--)
    {
        int i = 0;
        int j = k - 1;

        while(i < j)
        {
            int sum = arr[i] + arr[j];

            if(sum == arr[k])
            {
                cout << i << "," << j << "," << k << endl;
                found = true;
                return; 
            }
            else if(sum < arr[k])
                i++;
            else
                j--;
        }
    }

    if(!found)
        cout << "No sequence found." << endl;
}

int main()
{
    int t;
    cin >> t;

    while(t--)
    {
        int n, x;
        cin >> n;

        vector<int> arr;

        for(int i = 0; i < n; i++)
        {
            cin >> x;
            arr.push_back(x);
        }

        findSequence(arr, n);
    }

    return 0;
}