#include <bits/stdc++.h>

using namespace std;

bool isBoomerang(vector<vector<int>>& points) {
    int x1, x2, x3, y1, y2, y3;
    x1 = points[0][0];
    x2 = points[1][0];
    x3 = points[2][0];
    y1 = points[0][1];
    y2 = points[1][1];
    y3 = points[2][1];
    return (x1 * (y2-y3)) + (x2 * (y3-y1)) + (x3 * (y1-y2));
}