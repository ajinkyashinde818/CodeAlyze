#include<stdio.h>
int main(void){

    long int A,B;
    scanf("%ld %ld",&A,&B);
    long int kbsa,kbsb;
    for(int i=1;kbsa<=A*B;i++){
        kbsa = A*i;
      if(kbsa%B==0){
      	break;
      }
    }
    printf("%ld",kbsa);
    return 0;
}
