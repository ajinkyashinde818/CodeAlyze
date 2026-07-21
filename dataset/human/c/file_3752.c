#include<stdio.h>
int main(void){
  long int A,B;
  scanf("%ld %ld",&A,&B);
  long int i;
  long int j;
  if(A>=B){for(i=B;;i--){if(A%i==0&&B%i==0){break;}}
    printf("%ld",A*B/i);}
  if(B>A){for(j=A;;j--){if(A%j==0&&B%j==0){break;}}
    printf("%ld",A*B/j);} return 0;
}
