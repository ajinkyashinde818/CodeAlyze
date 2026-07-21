#include<stdio.h>
#include<string.h>

int main(void){


  int i,j;
  int n;
  int ans=0;
  int k;

  scanf("%d",&n);
  int h[n];

  scanf("%d",&k);
  for(i=0;i<n;i++){
    scanf("%d",&h[i]);
  }

  for(i=0;i<n;i++){
    if(h[i]>=k)
    ans++;
  }

  printf("%d",ans);



return 0;

}
