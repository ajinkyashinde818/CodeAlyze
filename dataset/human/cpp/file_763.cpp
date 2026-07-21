#include<iostream>
#include<algorithm>
#include<stdio.h>
using namespace std;


int main(){
  int R,G,B,N;
  int cnt =0;
  cin >> R;
  cin >> G;
  cin >> B;
  cin >> N;
  for(int i=0;i*R<N+1;i++){
     for(int j=0;i*R+j*G<N+1;j++){
         if((N-i*R-j*G)%B==0) cnt++;
     }
  }
  printf("%d",cnt);
   return 0;

}
