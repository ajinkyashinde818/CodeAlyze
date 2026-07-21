#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <cstring>
#include <ctime>
#include <queue>
using namespace std;
typedef long long ll;
const int maxn = 55;

string a[maxn],b[maxn];
int n,m;

bool solve(){
  for(int i=0;i+m<=n;i++)
  for(int j=0;j+m<=n;j++){
    bool sign=0;
    for(int k=0;k<m;k++)
    for(int r=0;r<m;r++)
    if(b[k][r]!=a[i+k][j+r])sign=1;
    if(!sign)return 1;
  }
  return 0;
}

int main() {
 // freopen("in.cpp","r",stdin);
  cin>>n>>m;
  for(int i=0;i<n;i++)cin>>a[i];
  for(int i=0;i<m;i++)cin>>b[i];
  if(solve())cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
  return 0;
}
