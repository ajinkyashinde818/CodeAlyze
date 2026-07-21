#include <stdio.h>

int main(){
  int a,b,k;
  int i = 0;
  
  scanf("%d", &a);
  scanf("%d", &b);
  scanf("%d", &k);
  
  int n = 1;
  int count = 0;
  int answer;
  for(n=100;n>= 1;n--){
    if(a%n == 0 && b%n == 0){
      count++;
        if(count == k){
          answer = n;
        }
    }
  }
  printf("%d",answer);
  
return 0;  
}
