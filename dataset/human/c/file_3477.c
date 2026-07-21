#include <stdio.h>
int main(){
  int n;
  unsigned long long int m;
  scanf("%d %llu",&n,&m);
  int i,A[n+1],time,ch=0,B[n+1],cur=1;
  for(i=1;i<n+1;i++){
    A[i]=0;
    scanf("%d",&time);
    B[i]=time;
  }
  time=0;
  A[1]=1;
  while(m>0){
    cur=B[cur];
    m -= 1;
    if(A[cur]!=2){
      int ha;
      ha=A[cur];
      ha=ha+1;
    }else{
      for(i=1;i<n+1;i++){
        if(A[i]==2){
          ch+=1;
        }
      }
      m=m%ch;
      for(i=1;i<n+1;i++){
        A[i]=0;
      }
    }
    A[cur]+=1;
  }
  printf("%d",cur);
  return 0;
}
