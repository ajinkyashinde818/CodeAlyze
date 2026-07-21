#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;



int main() {

  int N;
  cin >> N;

  bool exist = false;
  int k = 1;
  while(k*(k-1) <= 2*N) {
    if(k*(k-1) == 2*N){
      exist = true;
      break;
    }

    k += 1;
  }

  if(exist) {
    cout << "Yes" << endl;

    vector< vector<int> > A;
    A.resize(k);
    for(int i = 0; i < k; ++i) A.resize(k-1);

    int n = 1;
    cout << k<< endl;
    for(int i = 1; i <= k; ++i) {
      cout << k-1 << " ";

      int size = A[i-1].size();
      for(int s = 0; s < size; ++s) {
        cout << A[i-1][s] << " ";
      }

      for(int s = i+1; s <= k; ++s) {
        cout << n << " ";
        A[s-1].push_back(n);
        n += 1;
      }

      cout << endl;
    }
  }
  else {
    cout << "No" << endl;
  }

}
