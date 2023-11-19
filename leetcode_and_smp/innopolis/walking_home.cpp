using namespace std;

#include <cstdlib>
#include <iostream>
#include <vector>


int main(void) {
  int x = 0, y = 0, w = 0, s = 0;
  int t = 0;
  int ending_t = 0;
	
  cin >> x >> y >> s >> w;
  t = min(w, 2 * s);
	
  int diag = min(x, y) * t;
  int ending_coord = (max(x, y) - min(x, y));
  if (ending_coord % 2 == 0) {
	  ending_t = ending_coord * min(t, s);
  }
  else {
	  ending_t = (ending_coord - 1) * min(t, s) + s;
  }
	
  cout << diag + ending_t;
	
  return 0;
}