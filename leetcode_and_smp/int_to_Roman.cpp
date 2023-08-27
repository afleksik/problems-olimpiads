#include <string>
#include <iostream>

using namespace std;

string symba[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
int znach[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};

string intToRoman(int num) {
    string rim = "";
    for (int i = 0; i < 13; ++i) {
        while (num >= znach[i]) {
            rim += symba[i];
            num -= znach[i];
        }
}
return rim;
}