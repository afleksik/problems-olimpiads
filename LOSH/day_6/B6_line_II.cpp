/*
Формат ввода

Четыре числа – координаты точки на прямой и координаты вектора нормали к этой прямой.
Формат вывода

Три числа – коэффициенты A, B и C уравнения этой прямой.
*/

#include <iostream>

using namespace std;

struct V {
  double x{}, y{};
};

istream& operator>>(istream& in, V& p) {
  return in >> p.x >> p.y;
}

ostream& operator<<(ostream& out, V p) {
  return out << p.x << " " << p.y;
}

int main() {
    int x, y, a, b, c;
    V vec;
    cin >> x >> y >> vec;
    a = vec.x;
    b = vec.y;
    c = -a * x - b * y;
    cout << a << " " << b << " " << c; 

}