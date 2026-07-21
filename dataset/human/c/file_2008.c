#include <stdio.h>
 
int main(){
    int a;//解毒・美味しくない
    int b;//解毒・美味しい
    int c;//毒・美味しい
    int sum = 0;
    int flag = 0;
    scanf("%d %d %d", &a, &b, &c);
    if(c > a + b + 1){
      sum = a + b + 1 + b;
    }
    else{
      sum = b + c;
    }
  
  	printf("%d\n", sum);
    return 0;
}
