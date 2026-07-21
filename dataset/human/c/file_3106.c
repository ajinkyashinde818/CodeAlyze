#include<stdio.h>

int main (void){
  int k,n,a = 0;
  int house[200005];
  int dis[200005];

  scanf("%d %d",&k,&n);
  for(int i = 0;i < n;i++){
    scanf("%d",&house[i]);
  }

  for(int i = 1; i < n; i++){
    dis[i] = k - house[i] + house[i - 1];
  }
  dis[0] = house[n - 1] - house[0];

  a = k;

  for(int i = 0;i < n ;i++){
    if(dis[i] < a){
      a = dis[i];
    }
  }
printf("%d\n",a);
return 0;

}
