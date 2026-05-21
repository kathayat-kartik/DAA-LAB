#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int> &arr, int low, int high)
{
    int pivot = arr[high];
    int i = low-1;

    for(int j = low; j < high; j++)
    {
        if(arr[j] <= pivot)
        {  i++;
            swap(arr[i], arr[j]);
            
        }
    }

    swap(arr[i+1], arr[high]);
    return i+1;
}

int quickSelect(vector<int> &arr, int low, int high, int k)
{
    if(low <= high)
    {
        int pos = partition(arr, low, high);

        if(pos == k-1)
            return arr[pos];

        if(pos > k-1)
            return quickSelect(arr, low, pos-1, k);

        return quickSelect(arr, pos+1, high, k);
    }

    return -1;
}

int main()
{
    int T;
    cin >> T;

    while(T--)
    {
        int n;
        cin >> n;

        vector<int> arr(n);

        for(int i=0;i<n;i++)
            cin >> arr[i];

        int k;
        cin >> k;

        if(k > n || k <= 0)
        {
            cout<<"not present"<<endl;
            continue;
        }

        int result = quickSelect(arr,0,n-1,k);
        cout<<result<<endl;
    }
}