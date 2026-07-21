#include <stdio.h>
#include <math.h>

int main(){
  int N;
  scanf("%d",&N);

  int NumberOfDigits = 1;
  while(1){
    if(N/(int)pow(10,NumberOfDigits) == 0) break;
    NumberOfDigits++;
  }
  
  int digit[NumberOfDigits];
  int i;
  int temp = 0;
  for(i = 0; i < NumberOfDigits; i++){
    digit[i] = (int)((N%(int)pow(10,i+1) - temp)/pow(10,i));
    temp = (int)(digit[i] * pow(10,i)) + temp;
  }
  
//  for(i = 0; i < NumberOfDigits; i++){
//    printf("digit[%d] : %d\n",NumberOfDigits - i,digit[NumberOfDigits - i - 1]);
//  }

  int flag = 1;
  for(i = 0; i < NumberOfDigits; i++){
    if(digit[i] == 9){
      printf("Yes\n");
      flag--;
      break;
    }
  }
  if(flag){
    printf("No\n");
  }
  return 0;
}
