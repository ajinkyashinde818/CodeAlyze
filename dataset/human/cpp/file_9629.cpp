#include <bits/stdc++.h>
using namespace std;
const int max_m=50,max_n=50;
bool ans=false;
char a[max_m][max_m],b[max_n][max_n];

void check(int x,int y,int m,bool &ans){
  bool flag=false;
  for (int i=0;i<m;i++) {
    for (int j=0;j<m;j++) {
      if (a[x+i][y+j]!=b[i][j]) {
        flag=true;
        break;
      }
      else if (i==m-1 && j==m-1) ans=true;
    }
    if (flag) break;
  }
}

int main() {
  int n,m;
  cin>>n>>m;
  for (int i=0;i<n;i++) for (int j=0;j<n;j++) cin >> a[i][j];
  for (int i=0;i<m;i++) for (int j=0;j<m;j++) cin >> b[i][j];
  for (int i=0;i<n-m+1;i++) for (int j=0;j<n-m+1;j++) check(i,j,m,ans);
  if (ans) cout << "Yes" <<endl;
  else cout << "No" << endl;
}
