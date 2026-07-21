#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 1<<30;

int n, m;

bool find(vector<vector<char>> &a, vector<vector<char>> &b, int x, int y){
  bool match=true;
  for(int i=0;i<m;i++){
    for(int j=0;j<m;j++){
      if(b[i][j]!=a[i+x][j+y]){match=false;break;}
    }
    if(!match)break;
  }
  return match;
}

int main(){
  cin>>n>>m;
  vector<vector<char>> a(n, vector<char>(n)), b(m, vector<char>(m));
  for(int i=0;i<n;i++){
    string s;cin>>s;
    for(int j=0;j<n;j++)a[i][j]=s[j];
  }
  for(int i=0;i<m;i++){
    string s;cin>>s;
    for(int j=0;j<m;j++)b[i][j]=s[j];
  }
  bool ans=false;
  for(int x=0;x+m<=n;x++){
    for(int y=0;y+m<=n;y++){
      if(find(a, b, x, y)){ans=true;break;}
    }
    if(ans)break;
  }
  cout << (ans?"Yes":"No") << endl;
}
