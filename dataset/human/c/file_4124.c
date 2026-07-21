#include <stdio.h>

int main(){
  int a,b,k;
  scanf("%d %d %d",&a,&b,&k);
  int count = 0;
  int answer;
  for(int i = a; i > 0; i--){
    if(a % i == 0 && b % i == 0) count++;
    if(count == k){
      answer = i;
      break;
    }
  }
  printf("%d\n",answer);
  return 0;
}
