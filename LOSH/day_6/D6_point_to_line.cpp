/*
Формат ввода

Пять чисел – координаты точки и коэффициенты A, B и C уравнения прямой.
Формат вывода

Одно число – расстояние от точки до прямой.
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
  int x, y, a, b, c;
  cin >> x >> y >> a >> b >> c;

  printf("%f", abs((a * x + b * y + c) / (sqrt(pow(a, 2) + pow(b, 2)))));
} 