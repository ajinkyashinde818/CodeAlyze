#include <stdio.h>{
  int max(int a,int b){
    if(a>b){
      return a;
    }
    else{
      return b;
    }
  }
  int min(int a,int b){
    if(a<b){
      return a;
    }
    else{
      return b;
    }
  }
  int main(void){
    int n,i;
    scanf("%d",&n);
    int r[n];
    for(i=0;i<n;i++){
    scanf("%d",&r[i]);
    }

    int maxv=-2000000000;
    int minv=r[0];
    for(i=1;i<n;i++){
      maxv=max(maxv,r[i]-minv);
      minv=min(minv,r[i]);
    }

    printf("%d\n",maxv);
    return 0;
  }
