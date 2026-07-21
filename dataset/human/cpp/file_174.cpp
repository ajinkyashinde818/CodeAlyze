#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <iomanip>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const int mod=1000000007;

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
  int R,G,B,N;
  cin>>R>>G>>B>>N;
  int cnt=0;
  for(int r=0;r<=N;r++){
    for(int g=0;g<=N-r;g++){
      int Bb=N-R*r-G*g;
      if(Bb%B==0&&Bb/B>=0){cnt++;}
    }
  }
  cout<<cnt<<endl;
  return 0;
}
