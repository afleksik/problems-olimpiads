/*
Определить, принадлежит ли точка, заданная своими координатами, 
отрезку, который задается своими концами.
Формат ввода

Задано 6 целых чисел от -10 000 до 10 000, разделенных пробелами: точка (x,y) и 
две различных точки (x1, y1), (x2, y2), являющиеся концами отрезка.
Формат вывода

Выведите «YES» (без кавычек), если точка принадлежит отрезку. В противном случае, 
выведите «NO» (без кавычек). 
*/

#include <iostream>
#include <cmath>

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


double operator*(V a, V b) { // Скалярное произведение
  return a.x*b.x + a.y*b.y;
}

double operator^(V a, V b) { // Векторное произведение
  return a.x*b.y - a.y*b.x;
}


int main() {
    long double x1, y1, x2, y2, x3, y3, f, s;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    if ((x1 - x2) * (y3 - y2) == (x3 - x2) * (y1 - y2)) {
        if (min(y2, y3) <= y1 && (max(y2, y3) >= y1) && min(x2, x3) <= x1 && max(x2, x3) >= x1){
            cout << "YES";
            exit(0);
        }
    }
    cout << "NO";

    return 0;
}