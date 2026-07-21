//簡易競プロテンプレ
#include<bits/stdc++.h>
using namespace std;
int n, m;
string s[100], t[100];
int main(void){
 cin >> n >> m;
 for(int i=0;i<n;i++) cin >> s[i];
 for(int i=0;i<m;i++) cin >> t[i];

 for(int i=0;i<=n-m;i++)for(int j=0;j<=n-m;j++){
  bool ok = true;
  for(int k=0;k<m;k++)for(int l=0;l<m;l++){
   if (s[i+k][j+l] != t[k][l]) ok = false;
  }
  if (ok) {cout << "Yes" << endl; return 0;}
 } 
 cout << "No" << endl;
 return 0;
}
