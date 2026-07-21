#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int N;
  cin >> N;

  vector<int> A(N,0);
  vector<int> A2(N,0);
  vector<int> B(N,0);
  int x;
  for (int i = 0; i < N; i++) {
    cin >> x;
    A.at(x-1)++;
    A2.at(i) = x;
  }  
  for (int i = 0; i < N; i++) {
    cin >> x;
    B.at(x-1)++;
  }
  
  int m=0;
  int n=0;
  for (int i = 0; i < N; i++) {
    if (m < A.at(i)+B.at(i)) {
      m = A.at(i)+B.at(i);
      n = i;
    }
  }
  
  if (m>N) {
    cout << "No" << endl;
  }
  else {
    cout << "Yes" << endl;
    
    vector<int> B2(N,0);
    
    int x=0;
    for (int i = 0; i <= n; i++) {
      x += A.at(i);
    }
    int x2 = x-1;
    if (x == N) {
      x = 0;
    }
    
    for (int i = 0; i < N; i++) {
      while (B.at(n) == 0) {
        n++;
        if (n == N) {
          n = 0;
        }
      }      
      B2.at(x) = n+1;
      B.at(n)--;
      x++;
      if (x == N) {
        x = 0;
      }
    }
    
    int z;
    bool check = true;
    while (check) {
      check = false;
      for (int i = 0; i < N; i++) {
        if (A2.at(i)==B2.at(i)) {
          if (x2 == -1) {
            x2 = N-1;
          }
          check = true;
          z = B2.at(x2);
          B2.at(x2) = B2.at(i);
          B2.at(i) = z;
          x2--;
        }
      }
    }
    
    
    

    
    for (int i = 0; i < N; i++) {
      cout << B2.at(i);
      if (i < N-1) {
        cout << ' ';
      }
      else {
        cout << endl;
      } 
    }
    
  }

return 0;
}
