#include<stdio.h>

int main(void){
  int n;
  scanf("%d",&n);
  int d[n],q[n];
  for(int i=0;i<n;i++){
    scanf("%d %d",&d[i],&q[i]);
  }
    for(int i=2;i<n;i++){
      if(d[i]==q[i]){
        if(d[i-1]==q[i-1]){
          if(d[i-2]==q[i-2]){
            printf("Yes\n");
            return 0;
          }
        }
      }
    }
  printf("No\n");
  return 0;
}
