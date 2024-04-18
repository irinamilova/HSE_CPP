#include <iostream>
#include <cmath>

using namespace std;
 
int main() {
   int v, t, s;
   cin >> v >> t;
   s = (v*t % 109 + 109) % 109;
   cout << s;
   return 0;
}