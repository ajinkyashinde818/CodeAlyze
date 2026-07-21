#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <numeric>
#include <functional>

using namespace std;

vector<long long> g1(200002, 0);
vector<long long> g2(200002, 0);
int main(){
  long long n;
  cin >> n;

  for(long long i = 0; i < n; i++){
    cin >> g1[i];
  }
  g2 = g1;
  
  for(long long i = 0; i < n; i++){
    g1[i+1] = g1[i] + g1[i+1];
  }
  for(long long i = n-1; i > 0; i--){
    g2[i-1] = g2[i] + g2[i-1];
  }

  long long m = 999999999999;
  for(long long i = 0; i < n -1; i++){
    m = min(m, abs(g1[i] - g2[i+1]));
  }
  cout << m << endl;
  return 0;
}
