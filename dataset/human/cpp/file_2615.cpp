#include<bits/stdc++.h>
using namespace std;
inline void rd(int &x){
  int k, m=0;
  x=0;
  for(;;){
    k = getchar_unlocked();
    if(k=='-'){
      m=1;
      break;
    }
    if('0'<=k&&k<='9'){
      x=k-'0';
      break;
    }
  }
  for(;;){
    k = getchar_unlocked();
    if(k<'0'||k>'9'){
      break;
    }
    x=x*10+k-'0';
  }
  if(m){
    x=-x;
  }
}
inline void wt_L(char a){
  putchar_unlocked(a);
}
inline void wt_L(long long x){
  char f[20];
  int m=0, s=0;
  if(x<0){
    m=1;
    x=-x;
  }
  while(x){
    f[s++]=x%10;
    x/=10;
  }
  if(!s){
    f[s++]=0;
  }
  if(m){
    putchar_unlocked('-');
  }
  while(s--){
    putchar_unlocked(f[s]+'0');
  }
}
template<class S, class T> inline S max_L(S a,T b){
  return a>=b?a:b;
}
int N;
int A[100000];
int main(){
  int i, j;
  long long dp0, dp1, nx0, nx1;
  rd(N);
  {
    int Lj4PdHRW;
    for(Lj4PdHRW=0;Lj4PdHRW<N;Lj4PdHRW++){
      rd(A[Lj4PdHRW]);
    }
  }
  dp0 = 0;
  dp1 = -4611686016279904256LL;
  for(i=0;i<N;i++){
    nx0 =max_L(dp0 + A[i], dp1 - A[i]);
    nx1 =max_L(dp0 - A[i], dp1 + A[i]);
    dp0 = nx0;
    dp1 = nx1;
  }
  wt_L(dp0);
  wt_L('\n');
  return 0;
}
// cLay varsion 20190601-1

// --- original code ---
// int N, A[1d5];
// {
//   int i, j;
//   ll dp0, dp1, nx0, nx1;
//   
//   rd(N,A(N));
//   dp0 = 0;
//   dp1 = -ll_inf;
//   rep(i,N){
//     nx0 = max(dp0 + A[i], dp1 - A[i]);
//     nx1 = max(dp0 - A[i], dp1 + A[i]);
//     dp0 = nx0;
//     dp1 = nx1;
//   }
//   wt(dp0);
// }
