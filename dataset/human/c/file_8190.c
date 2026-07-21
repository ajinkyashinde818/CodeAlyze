#include <stdio.h>

int main(){
    int A,B,C,D;
    int sq1,sq2;
    scanf("%d %d %d %d",&A,&B,&C,&D);
    sq1 = A*B;
    sq2 = C*D;
    if(sq1 > sq2){
      printf("%d\n",sq1);
    }else if(sq1 < sq2){
      printf("%d\n",sq2);
    }else{
      printf("%d\n",sq1);
    }
}
