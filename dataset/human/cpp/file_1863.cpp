#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<numeric>
#include<map>
#include<limits>
#include<unordered_map>
using namespace std;

#define rep(i,s,n) for(int i=s;i<n;i++)
#define dow(i,n,s) for(int i=n-1;i>=s;i--)
#define all(a) a.begin(),a.end()
#define Sort(a) sort(all(a))
#define Qsort(a,size) qsort(a,size,sizeof(*a),compare_int)
//#define rng(a,b,e) a.begin()+b,a.begin()+e
//#define DEBUG
typedef pair<int,int> II;
typedef unsigned long ul;
typedef long long ll;
typedef unsigned long long ull;
bool compare_by_second(II a,II b) {
  if(a.second != b.second) return a.second < b.second;
  return a.first < b.first;
}
bool compare_int(const void *a, const void *b) { return *(int *)a - *(int *)b; }

const int INF = 1e+9;
const int MAX_N = 2e+5;
const int MAX_M = 1e+5;

int n,m;
int e[MAX_M];
unordered_map<int,int> um;
vector<int> num;

//void solve();

int main() {

  cin>>n>>m;
  rep(i,0,m) cin>>e[i];
  dow(i,m,0) {
    if(um.find(e[i]) == um.end()) {
      um[e[i]] = 1;
      num.push_back(e[i]);
    }
  }
  rep(i,0,n) if(um.find(i+1) == um.end()) num.push_back(i+1);
  rep(i,0,num.size()) cout<<num[i]<<endl;
  return 0;
}
