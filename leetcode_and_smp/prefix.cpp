#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

int prefix_sum(const vector<int> &array, const int size, vector<int> &sums) {
    int sum = 0;

    for (int i = 0; i < size; ++i) {
        sum += array[i];
        sums[i] = sum;
    }

    return sum;
}


int main() {
    int size = 0;

    srand(time(NULL));

    cout << "enter size: ";
    cin >> size;
    
    vector<int> sums(size, 0);
    vector<int> array(size);
    
    for (int i = 0; i < size; ++i) {
        array[i] = rand() % 90 + 10; // [10 90)
    }

    for (int i = 0; i < size; ++i) {
        cout << array[i] << " ";
    }
    cout << endl;

    prefix_sum(array, size, sums);
 
    // есть ли заданная сумма на отрезке:

    int l = 0, given_sum = 0, r = 0;
    cin >> given_sum;

    for (int i = 0; i < size; ++i) {
        if (sums[r] - sums[l] < given_sum) {
            r++;
        }
        else if (sums[r] - sums[l] > given_sum) {
            cout << "YES";
        }
        else {
            cout << "YES" << endl;
        }
    }
    cout << endl;

/// 1 2 3 4  5  6
/// 1 3 6 10 15 21

    return 0;
}

