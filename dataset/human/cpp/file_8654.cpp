#include <bits/stdc++.h>
using namespace std;
long long n,m;
string s[100],t[100];
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
bool B[55][55];

int main(){
  cin >> n >> m;
  for(int i=0;i<n;i++){
    cin >> s[i];
  }
  for(int i=0;i<m;i++){
    cin >> t[i];
  }
  for(int i=0;i<=n-m;i++){
    for(int j=0;j<=n-m;j++){
      int cnt=0;
      if(s[i][j]==t[0][0]){
        for(int k=0;k<m;k++){
          for(int l=0;l<m;l++){
            if(s[k+i][l+j]==t[k][l]){
              cnt++;
            }
          }
        }
        if(cnt==m*m){
          cout << "Yes" << endl;
          return 0;
        }
      }
    }
  }
  cout << "No" << endl;
  return 0;
}
