#include<stdio.h>
int main(){
  int a[21],b[21],c[21],i,n,ans=0;
  scanf("%d",&n);
  for(i=0; i<n; i++){
    scanf("%d",&a[i]);
  }
  for(i=0; i<n; i++){
    scanf("%d",&b[i]);
    ans+=b[i];
  }
  // printf("%d\n",ans);
  for(i=0; i<n-1; i++){
    scanf("%d",&c[i]);
  }
  for(i=0; i<n-1; i++){
    if(a[i]+1==a[i+1]){
      ans+=c[a[i]-1];
      // printf("%d\n",ans);
    }
  }
  
  printf("%d\n",ans);
  return 0;

}
