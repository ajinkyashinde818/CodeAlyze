#include<stdio.h>
#define NUM 200000

int main(){
  int i,n,R_t,mx,mi;
  int a[NUM];

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
  }

  mi=a[0];
  mx=a[1]-a[0];
  for(i=1;i<n;i++){
    if(a[i-1]<mi){
      mi=a[i-1];
    }
    R_t=a[i]-mi;
    if(R_t>mx){
      mx=R_t;
    }
    
   
  }

  printf("%d\n",mx);
  
  return 0;
}
