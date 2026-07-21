#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main() {
  int N,M;
  cin>>N>>M;
  string A[50],B[50];
  for (int i(0);i<N;i++)cin>>A[i];
  for (int i(0);i<M;i++)cin>>B[i];
  for (int i(0);i<N;i++){
    for (int j(0);j<N;j++){
      bool flag=true;
      for (int im(0);im<M;im++){
        for (int jm(0);jm<M;jm++){
          if (A[i+im][j+jm]!=B[im][jm]) flag=false;
        }
      }
      if (flag==true){
        cout << "Yes" <<endl;
        return 0;
      }
    }
  }
  cout << "No" << endl;
  return 0;
}
