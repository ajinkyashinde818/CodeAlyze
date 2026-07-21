#include<bits/stdc++.h>
using namespace std;
typedef long long int llint;
typedef long int lint;
typedef vector<char> vchar;
typedef vector<int> vint;
typedef vector<vector<int>> vvint;
typedef vector<vector<char>> vvchar;
#define vsort(v) sort((v).begin(), (v).end())
#define vrsort(v) sort((v).rbegin(), (v).rend())
#define vreverse(v) reverse((v).begin(), (v).end())
#define pb(a) push_back(a)
#define INF 1000000007
#define MOD 1e9+7
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  //input
  lint n,i;cin>>n;vector<long long> a(n);
  for(i=0;i<n;i++){cin>>a[i];}
  //caricurate
  for(i=1;i<n;i++){
   a[i]+=a[i-1]; 
  }
  lint mn=2000000009;lint nw;
  for(i=0;i<n-1;i++){
    nw=abs((a[n-1]-a[i])-(a[i]));
    if(mn>nw){mn=nw;}
  }
  //output
  cout<<mn<<endl;
}
