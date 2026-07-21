#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
const int N = 1e5+5;
const dd eps = 1e-8;
const ll mod = 1e9+7;


int n,m;

int main(){
  // freopen("input.txt","r",stdin);
  cin>>n>>m;
  if(n >= 10) cout<<m<<endl;
  else cout<<m+(100*(10-n))<<endl;
  return 0;
}
