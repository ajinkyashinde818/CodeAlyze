#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<ctime>
#include<cctype>
#include<climits>
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<list>
#include<queue>
#include<deque>
#include<algorithm>
#include<numeric>
#include<utility>
#include<complex>
#include<memory>
#include<functional>
 
using namespace std;
 
#define ALL(g) (g).begin(),(g).end()
#define REP(i, x, n) for(int i = x; i < n; i++)
#define rep(i,n) REP(i,0,n)
#define F(i,j,k) fill(i[0],i[0]+j*j,k)
#define P(p) cout<<(p)<<endl;
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define INF 1<<25
#define pb push_back
 
typedef vector<int> vi;
typedef vector<long long> vl;
typedef vector<double> vd;
typedef pair<int,int> pii;
typedef pair<long,long> pll;
typedef long long ll;

int main(){
  int n,m;
  if(scanf("%d %d",&n,&m)<2){
    exit(1);
  }

  char A[51][51];
  char B[51][51];
  char s[51];
  rep(i,n){
    scanf("%s",s);
    rep(j,n)
      A[i][j] = s[j];
  }

  rep(i,m){
    scanf("%s",s);
    rep(j,m)
      B[i][j] = s[j];
  }


  int flag=0;
  rep(i,n-m+1){
    rep(j,n-m+1){

      rep(k,m){

        rep(l,m){
          if(A[i+k][j+l]!=B[k][l]) {flag=-1;break;}
          if(k==m-1&&l==m-1) flag=1;
        }

        if(flag==-1) {flag=0;break;}
        if(flag==1) break;
      }
      if(flag==1) break;
    }
    if(flag==1) break;
  }

  if(flag==1)
    printf("Yes\n");
  else
    printf("No\n");

return 0;
}
