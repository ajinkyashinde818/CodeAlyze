#include <stdio.h>

int main(){
  int i, k, n, max=0, max_i, ans=0;
  scanf("%d%d",&k,&n);
  int a[n];
  for(i=0;i<n;i++) scanf("%d",&a[i]);
  //最も長いところを探す
  for(i=0;i<n-1;i++){
    ans+=a[i+1]-a[i];
    if(a[i+1]-a[i]>max){
      max=a[i+1]-a[i];
      max_i=i;
    }
  }
  if(k-a[n-1]+a[0]>max){
    printf("%d",ans);
  }
  else{
    printf("%d",k-(a[max_i+1]-a[max_i]));
  }
}
