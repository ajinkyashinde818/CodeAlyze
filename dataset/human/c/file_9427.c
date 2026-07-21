#include<stdio.h>

int main(){
  int n,d,x;
  int i,j;
  int a[120];
  int ans = 0;
  scanf("%d",&n);
  scanf("%d",&d);
  scanf("%d",&x);
  ans += x;
  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
  }

  for(i=0;i<n;i++){

    for(j=1;j<=d;j+=a[i]){
      ans+=1;
    }


  }

  printf("%d",ans);

  return 0;
}
