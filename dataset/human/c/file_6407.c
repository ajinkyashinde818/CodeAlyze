#include<stdio.h>

int main(){

  int n,i,j=0,x,min;
  int r[200000];

  
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&r[i]);
    if(i==0)min=r[i];
    if(i==1)x=r[i]-min;
    if(i>0){
      if(r[i]-min>x) x=r[i]-min;
      if(r[i]<min)min=r[i];
  }
  }
  printf("%d\n",x);
}
