#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <random>
#include <chrono>
#include <queue>
#include <math.h>
using namespace std;

int main(){
  int n,k;
  cin >> k>>n;
  k=min(0,k-10);
  cout << n-100*k << endl;
}
