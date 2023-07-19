#include <iostream>
#include <math.h>

using namespace std;


float fun(float x){
    return x*x + sqrt(x);
}


float binarySearch(float C)
{
    float l = 0.0;
    float r = C;
    float m = 0.0;
    float eps = 0.000001;
    while (r - l > eps)
    {
        m = (r + l) / 2;
        if (fun(m) - C > 0)
            r = m;
        else
            l = m;
    }
    return m;
}


int main(){

    float C = 0.0;
    cin >> C;
    printf("%.6f", binarySearch(C));
}