# https://codeforces.com/contest/1878/problem/C

l = int(input())
for i in range(l):
    m = input().split()
    n = int(m[0])
    k = int(m[1])
    x = int(m[2])
    if ((2*n-k+1)*k/2 >= x) and ((1+k)*k/2 <= x):
        print('yes')
    else:
        print('no')


#include <iostream>
#include <vector>
#
#using namespace std;
#
#
#int main()
#{
#    int t;
#    cin >> t;
#    for (int i = 0; i < t; ++i) {
#        int n, k, x;
#        cin >> n >> k >> x;
#        if (((2 * n - k + 1) * k / 2 >= x) && ((1 + k) * k / 2 <= x)) {
#            cout << "yes";
#        }
#        else {
#            cout << "NO";
#        }
#    }
#    return 0;
#} 