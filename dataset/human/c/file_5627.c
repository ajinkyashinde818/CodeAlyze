#include <stdio.h>

int main(){
  long long int score, group, rest, operation;
  scanf("%lld", &score);
  group = score / 11;
  rest = score % 11;
  if(rest >= 1 && rest <= 6){
    operation =  2 * group + 1;
  }else if(rest == 0){
    operation = 2 * group;
  }else{
    operation = 2 * (group + 1);
  }
  printf("%lld\n", operation);
  return 0;
}
