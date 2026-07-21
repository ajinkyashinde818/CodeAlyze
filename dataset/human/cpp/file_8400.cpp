#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <iomanip>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int INF=1001001001;
vector<pair<int64_t,int64_t>>prime_factorize(int64_t x){
  vector<pair<int64_t,int64_t>>p;
  for(int64_t i=2;i*i<=x;i++){
    int cnt=0;
    if(x%i==0){
    while(x%i==0){cnt++;x/=i;}
    p.push_back(make_pair(i,cnt));
    }
  }
  if(x!=1){p.push_back(make_pair(x,1));}
  return p; 
}
int main() {
  int N,M;
  cin>>N>>M;
  vector<string>A(N),B(M);
  for(int i=0;i<N;i++){
    cin>>A[i];
  }
  for(int i=0;i<M;i++){
    cin>>B[i];
  }
  for(int i=0;i<=N-M;i++){
    for(int j=0;j<=N-M;j++){
      bool ok=true;
      for(int p=0;p<M;p++){
        for(int q=0;q<M;q++){
          int x=i+p,y=j+q;
          if(B[p][q]!=A[y][x]){
            ok=false;
          }
        }
      }
      if(ok){cout<<"Yes"<<endl;return 0;}
    }
  }
  cout<<"No"<<endl;
  return 0;
}
