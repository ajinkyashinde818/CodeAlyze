#include <iostream>
#include <algorithm>

using namespace std;

int A[100001],B[1000][1000];

int main(){
  int i,j,N,f=0;
  cin >> N;
  A[0]=0;
  for (i=1;i<1000;++i) {
    A[i] = A[i-1]+i;
    if (N==A[i]) {
      f=i;
      break;
    }
  }
  if (f==0) {
    cout << "No" << endl;
    return 0;
  }
  cout << "Yes" << endl;
  cout << f+1 << endl;
  int k=1;
  for (i=0;i<f+1;++i) {
    for (j=i+1;j<f+1;++j) {
      B[i][j]=k;
      k++;
    }
  }
  for (i=0;i<f+1;++i) {
    cout << f;
    for (j=0;j<i;++j) {
      cout << " " << B[j][i];
    }
    for (j=i+1;j<f+1;++j) {
      cout << " " << B[i][j];
    }
    cout << endl;
  }
  return 0;
}
