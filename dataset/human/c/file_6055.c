#include <stdio.h>
#define N 200000 
int main(){
  int a[N],n,fx,i,tmin;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
    if(a[i]-tmin>fx){
      fx = a[i]-tmin;
    }
    if( i==0 ){
      tmin=a[i];
      fx=-a[i];
    }
    if(a[i]<tmin){
      tmin = a[i];
    }


  }

  printf("%d\n",fx);

  return 0;
}
