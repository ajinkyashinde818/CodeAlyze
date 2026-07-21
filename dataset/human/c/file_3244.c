#include<stdio.h>

int main(){
  int i;
  int k,n;
  scanf("%d %d",&k,&n);
  int a[n+1];
  for(i=0;i<n;i++)
    scanf("%d",&a[i]);
  
  int min=k;  
  //i番目の家から反時計回りに移動する時
  for(i=1;i<=n;i++){
    if(i==n){
      if(k-(a[0]+k-a[n-1])<min)
        min=k-(a[0]+k-a[n-1]);
    }
    else{
      if(k-(a[i]-a[i-1])<min)
        min=k-(a[i]-a[i-1]);
    }
  }
  //i番目の家から時計回りに移動する時
  for(i=1;i<=n;i++){
    if(i==1){
      if(k-(a[0]+k-a[n-1])<min)
        min=k-(a[0]+k-a[n-1]);
    }
    else{
      if(k-(a[i-1]-a[i-2])<min)
        min=k-(a[i-1]-a[i-2]);
    }
  }
  
  printf("%d",min); 
}
