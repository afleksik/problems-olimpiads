/*


Выясните, пересекаются ли два отрезка. Два отрезка считаются пересекающимися, если у них есть хотя бы одна общая точка.
Формат ввода

В первой строке заданы четыре целых числа — координаты концов (x1, y1), (x2, y2) первого отрезка.

Во второй строке заданы четыре целых числа — координаты концов (x3, y3), (x4, y4) второго отрезка.

Значения координат не превосходят 104 по абсолютному значению.
Формат вывода

Выведите YES, если отрезки имеют общие точки, или NO в противном случае.
Пример 1
Ввод
Вывод

1 2 1 2
1 2 1 2

	

YES

Пример 2
Ввод
Вывод

3 3 5 6
5 6 3 3

	

YES

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

V operator+(V a, V b) {
  return {a.x + b.x, a.y + b.y};
}

V operator-(V a, V b) {
  return {a.x - b.x, a.y - b.y};
}

double operator*(V a, V b) { // Скалярное произведение
  return a.x*b.x + a.y*b.y;
}

double operator^(V a, V b) { // Векторное произведение
  return a.x*b.y - a.y*b.x;
}

double len2(V a) {
  return a*a;
}

double len(V a) {
  return sqrt(len2(a));
}

double dist2(V a, V b) {
  return len2(a - b);
}

double dist(V a, V b) {
  return sqrt(dist2(a, b));
}

struct Line {
  double a{}, b{}, c{};
};

Line create_line(V p, V q) {
  double a = p.y - q.y;
  double b = q.x - p.x;
  double c = -a*p.x - b*p.y;
  return {a, b, c};
}

const double INF = 1e16;

V intersect(Line l1, Line l2) {
  if (l1.b*l2.a - l1.a*l2.b == 0) {
    return {-INF, -INF};
  }

  return {
    (l1.c*l2.b - l2.c*l1.b) / (l1.b*l2.a - l1.a*l2.b),
    (l2.c*l1.a - l1.c*l2.a) / (l1.b*l2.a - l1.a*l2.b)
  };
}

double dist(V p, Line l) {
  return abs((l.a * p.x + l.b * p.y + l.c) / sqrt(l.a*l.a + l.b*l.b));
}


int main() {
    int x_a = 0, y_a = 0, x_b = 0, y_b = 0;
    int x_c = 0, y_c = 0, x_d = 0, y_d = 0;
    V a_b, a_c, a_d, c_d, c_b, c_a;

    cin >> x_a >> y_a >> x_b >> y_b;
    cin >> x_c >> y_c >> x_d >> y_d;

    a_b.x = x_b - x_a;
    a_b.y = y_b - y_a;

    a_c.x = x_c - x_a;
    a_c.y = y_c - y_a;

    a_d.x = x_d - x_a;
    a_d.y = y_d - y_a;

    c_d.x = x_d - x_c;
    c_d.y = y_d - y_c;

    c_b.x = x_b - x_c;
    c_b.y = y_b - y_c;

    c_a.x = x_c - x_a;
    c_a.y = y_c - y_a;

    if (((operator^(a_b, a_c) * operator^(a_b, a_d)) < 0) && ((operator^(c_d, c_b) * operator^(c_b, c_a)) < 0)) {
        cout << "NO";
    }
    else {
      cout << "YES";
    }


    return 0;
}
