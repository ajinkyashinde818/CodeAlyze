#include<stdio.h>
int main(){

    int n,d1,d2,ans=0;
    scanf("%d", &n);

    for(;n>0;n--){
      scanf("%d %d", &d1, &d2);
      if(d1==d2){
        ans++;
      }else if(ans>=3){        
      }else{
      	ans=0;
      }
        
    }
    if (ans < 3){
      printf("No");
    }else{
      printf("Yes");
    }
  return 0;
}
