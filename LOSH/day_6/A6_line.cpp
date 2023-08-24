/*
Формат ввода

Четыре числа – координаты двух различных точек на прямой.
Формат вывода

Три числа – коэффициенты A, B и C уравнения этой прямой.
*/

#include <iostream>

using namespace std;

int main() {
    int x_o = 0, y_o = 0, x_s = 0, y_s = 0;
    cin >> x_o >> y_o >> x_s >> y_s;
    int a = 0, b = 0, c = 0;
    a = -(y_o - y_s);
    b = x_o - x_s;
    c = -a * x_o - b * y_o;

    cout << a << " " << b << " " << c;

    return 0;
}