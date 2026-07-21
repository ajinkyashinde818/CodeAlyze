#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <iostream>
using namespace std;
int main(){
  int N,M;bool f;
  char A[51][51],B[51][51];
  scanf("%d %d",&N,&M);
  for(int i=1;i<=N;i++){
    scanf(" %c",&A[i][1]);
    for(int j=2;j<=N;j++) scanf("%c",&A[i][j]);
  }
  for(int i=1;i<=M;i++){
    scanf(" %c",&B[i][1]);
    for(int j=2;j<=M;j++) scanf("%c",&B[i][j]);
  }
  for(int i=1;i<=N-M+1;i++){
    for(int j=1;j<=N-M+1;j++){
      if(A[i][j]==B[1][1]){
        f=true;
        for(int k=i;k<=i+M-1;k++){
          for(int l=j;l<=j+M-1;l++){
            if(A[k][l]!=B[k-i+1][l-j+1]){
              f=false;break;
            }
            if(!f) break;
          }
        }
        if(f){
          printf("Yes\n");
          return 0;
        }
      }
    }
  }
  printf("No\n");
  return 0;
}
