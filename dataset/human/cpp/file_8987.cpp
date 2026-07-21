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
inline int rd(char c[]){
  int i, sz=0;
  for(;;){
    i = getchar_unlocked();
    if(i!=' '&&i!='\n'&&i!='\r'&&i!='\t'&&i!=EOF){
      break;
    }
  }
  c[sz++] = i;
  for(;;){
    i = getchar_unlocked();
    if(i==' '||i=='\n'||i=='\r'||i=='\t'||i==EOF){
      break;
    }
    c[sz++] = i;
  }
  c[sz]='\0';
  return sz;
}
inline void wt_L(char a){
  putchar_unlocked(a);
}
inline void wt_L(const char c[]){
  int i=0;
  for(i=0;c[i]!='\0';i++){
    putchar_unlocked(c[i]);
  }
}
int N;
int M;
char A[50][52];
char B[50][52];
int main(){
  int i, j, k, res=0, x, y;
  rd(N);
  rd(M);
  {
    int Lj4PdHRW;
    for(Lj4PdHRW=0;Lj4PdHRW<N;Lj4PdHRW++){
      rd(A[Lj4PdHRW]);
    }
  }
  {
    int KL2GvlyY;
    for(KL2GvlyY=0;KL2GvlyY<M;KL2GvlyY++){
      rd(B[KL2GvlyY]);
    }
  }
  for(x=0;x<N-M+1;x++){
    for(y=0;y<N-M+1;y++){
      k = 0;
      for(i=0;i<M;i++){
        for(j=0;j<M;j++){
          if(A[i+x][j+y] == B[i][j]){
            k++;
          }
        }
      }
      if(k==M*M){
        wt_L("Yes");
        wt_L('\n');
        return 0;
      }
    }
  }
  wt_L("No");
  wt_L('\n');
  return 0;
}
// cLay varsion 20190721-1

// --- original code ---
// int N, M;
// char A[50][52], B[50][52];
// {
//   int i, j, k, x, y, res = 0;
//   
//   rd(N,M,A(N),B(M));
// 
//   rep(x,N-M+1) rep(y,N-M+1){
//     k = 0;
//     rep(i,M) rep(j,M) if(A[i+x][j+y] == B[i][j]) k++;
//     if(k==M*M){
//       wt("Yes");
//       return 0;
//     }
//   }
// 
//   wt("No");
// }
