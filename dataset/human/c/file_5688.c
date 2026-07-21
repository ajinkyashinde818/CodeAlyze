#include<stdio.h>

int main(){
  int r[210000]={};
  int n=0,max=-999999999,min;
  int i=0,j=0;

  scanf("%d",&n);
  for(i=0;i<n;i++)
    scanf("%d",&r[i]);

  min=r[0];
  for(i=1;i<n;i++){
    if(max<r[i]-min) max=r[i]-min;
    if(min>r[i]) min=r[i];
  }
    
  printf("%d\n",max);
  
  return 0;
}
