#include <iostream>
#include <algorithm>
#include <cmath>
#include <limits>
#include <vector>
#include<cstdio>
#include<bits/stdc++.h>
using namespace std;
using ll =long long;

int main (void) {
  int N,M;
  cin >>  N >> M;
  char A[50][50], B[50][50];
  for (int i=0; i<N; i++) {
    for (int j=0; j<N; j++) {
      cin >> A[i][j];
    }
  }
  for (int i=0; i<M; i++) {
    for (int j=0; j<M; j++) {
      cin >> B[i][j];
    }
  }
  
  int ans=0;
  int flag=0;
  
  for (int i=0; i<(N-M)+1; i++) {
      for (int j=0; j<(N-M)+1; j++) {
      flag=1;
        for (int k=0; k<M; k++) {
          for (int l=0; l<M; l++) {
            if (A[i+k][j+l] != B[k][l]) {
              flag=0;
            }
          }
        }
        if (flag==1){
          ans=1;
        }
      }
  }
  cout << (ans? "Yes":"No");
  return 0;
}
