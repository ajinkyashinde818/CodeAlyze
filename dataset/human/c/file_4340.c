#include<stdio.h>
int main(){
  int i;//制御変数
  int n,d1[101],d2[101];
  scanf("%d",&n);
  for(i=0;i<n;i++)
    scanf("%d %d",&d1[i],&d2[i]);

  for(i=0;i<n;i++){
    if(d1[i]==d2[i]){//条件1達成
      if(d1[i+1]==d2[i+1]){//条件2達成
        if(d1[i+2]==d2[i+2]){//条件3達成
          printf("Yes");
          return 0;
        }
      }
    }
  }
  printf("No");
  return 0;
}
