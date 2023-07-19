#include <iostream>
#include <vector>

using namespace std;


int Last(int *nums, int n, int target)
{
    int low = 0;
    int high = n - 1;
    int result = 0;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (target == nums[mid])
        {
            result = mid;
            low = mid + 1;
        }
        else if (target < nums[mid]) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    return result + 1;
}



int main(){
    int n, m, a_i, x_i;
    cin >> n;
    cin >> m;
    int *A = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; ++i){
        cin >> a_i;
        A[i] = a_i;
    }

    for (int j = 0; j < m; ++j){
        cin >> x_i;
        cout << Last(A, n, x_i) << "\n";
    }
    return 0;
}