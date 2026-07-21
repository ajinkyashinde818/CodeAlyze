#include<stdio.h>
typedef long long int lli;
int main() {
  int n;
  scanf("%d", &n);
  int count=0;
  int temp=0;
  while(n--){
      int a,b;
      scanf("%d %d", &a, &b);
      if(a==b){
          temp++;
      }
      else{
          temp=0;
      }
      if(temp>count){
          count=temp;
      }
  }
  
  if(count>=3){
      printf("Yes\n");
  }
  else{
      printf("No\n");
  }

  return 0;
}
