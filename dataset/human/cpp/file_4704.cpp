#include <bits/stdc++.h>
using namespace std;

int main() {
  int count = 0;
  int rating = 0;
  
  int result = 0;
  
  cin >> count >> rating;
  
  if (count < 10) {
    result = rating + (100 * (10 - count));
  } else {
    result = rating;
  }
  
  cout << result << endl;
}
