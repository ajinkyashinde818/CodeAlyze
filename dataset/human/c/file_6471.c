#include <stdio.h>
#define MAX 200000
int max(int,int);
int min(int,int);


int main(){
  int n,i,maxv,minv;
  int R[MAX];

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&R[i]);
  }
  maxv=-2000000000;
  minv=R[0];
  for(i=1;i<n;i++){
    maxv=max(maxv,R[i]-minv);
    minv=min(minv,R[i]);
  }
  printf("%d\n",maxv);



  return 0;
}

int max(int a,int b){
  if(a>b){
    return a;
  }
  else{
    return b;
  }
}

int min(int a,int b){
  if(a>b){
    return b;
  }
  else{
    return a;
  }
}
