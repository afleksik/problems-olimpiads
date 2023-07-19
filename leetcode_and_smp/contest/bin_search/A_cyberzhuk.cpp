#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;

int binarySearch(int arr[], int l, int r, int x)
{
    while (l <= r)
    {
        int m = l + (r - l) / 2;
        if (arr[m] == x)
            return m;
        if (arr[m] < x)
            l = m + 1;
        else
            r = m - 1;
    }
    return -1;
}

int main()
{
    int n, num_in, m, num_pr;
    cin >> n;
    int *collection = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; ++i)
    {
        cin >> num_in;
        collection[i] = num_in;
    }

    cin >> m;
    int *search = (int *)malloc(m * sizeof(int));

    for (int j = 0; j < m; ++j)
    {
        cin >> num_pr;
        search[j] = num_pr;
    }

    for (int k = 0; k < m; ++k)
    {
        if (binarySearch(collection, 0, n, search[k]) == -1)
        {
            cout << "NO\n";
        }
        else
        {
            cout << "YES\n";
        }
    }
    return 0;
}