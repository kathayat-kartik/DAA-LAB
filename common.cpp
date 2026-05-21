#include <iostream>
#include <vector>
using namespace std;

void commonElements(vector<int> A, vector<int> B, int m, int n)
{
    int i = 0, j = 0;

    while(i < m && j < n)
    {
        if(A[i] == B[j])
        {
            cout << A[i] << " ";
            i++;
            j++;
        }
        else if(A[i] < B[j])
            i++;
        else
            j++;
    }

    cout << endl;
}

int main()
{
    int T;
    cin >> T;

    while(T--)
    {
        int m;
        cin >> m;

        vector<int> A(m);
        for(int i = 0; i < m; i++)
            cin >> A[i];

        int n;
        cin >> n;

        vector<int> B(n);
        for(int i = 0; i < n; i++)
            cin >> B[i];

        commonElements(A, B, m, n);
    }

    return 0;
}