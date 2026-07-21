#include<stdio.h>
#define N 200000
int main(){
  int a,i,b[N],min,max,c,d;

  scanf("%d",&a);
  for(i=0;i<a;i++){
    scanf("%d",&b[i]);
  }
  min=b[0];
  max=b[0];
  c=b[1]-b[0];
  for(i=0;i<a;i++){
    if(min>b[i]){
      min=b[i];
      max=b[i];
    }
    if(max<b[i]){
      max=b[i];
    }
    if(max-min>c){
      c=max-min;
    }
  }
  
  if(max==b[a-1]&&min==b[a-1]){
    d=b[1]-b[0];
    for(i=0;i<a-1;i++){
      if(b[i+1]-b[i]>d){
	d=b[i+1]-b[i];
      }
    }
    c=d;
  }
  printf("%d\n",c);
  return 0;
}
