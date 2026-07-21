#include<stdio.h>
int main(){
  int n,i,a[2000000],minv,j,maxv=0;
  scanf("%d",&n);
  for (i = 0; i < n; i++){
    scanf("%d",&a[i]);  
}
  
  
  minv = a[0];
  maxv = a[1]-minv;
  for(j = 1;j <= n-1; j++){
  if(maxv >a[j]-minv)
    maxv = maxv;
  else if(maxv <a[j]-minv)
    maxv =a[j]-minv;
  if(minv<a[j])
    minv =minv;
  else if(minv >a[j])
    minv = a[j];

  }
   
     
 printf("%d\n",maxv);
     
 
 return 0;
}
