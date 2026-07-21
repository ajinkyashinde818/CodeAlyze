#include<stdio.h>

int main(){
  int k,n;
  int ans = 0;
  scanf("%d %d",&k,&n);
  
  int a[n];
  
  for(int i=0;i<n;i++){
    scanf("%d",&a[i]);
  }
  
  int max = 0;
  int j=0;
  for(int i=0;i<n-1;i++){
    if((a[i+1]-a[i])>max){
      max=a[i+1]-a[i];
      j=i;
    }
  }
  
  ans = a[j]+k-a[j+1];
    if((k-a[n-1]+a[0])>max){
      max = k-a[n-1];
      j=n-1;
      ans=a[n-1]-a[0];
    }
    
    

    printf("%d",ans);
}
