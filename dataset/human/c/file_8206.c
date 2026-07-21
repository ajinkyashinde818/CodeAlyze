#include<stdio.h>
int main()
{
    int A,B,C,D;
    scanf("%d %d %d %d",&A,&B,&C,&D);
    A=A*B;
    C=C*D;
    if(A>C){
            printf("%d",A);

    }
    else  if(C>A){
        printf("%d",C);
    }
    else if(A=C){
        printf("%d",A);
    }
    else {
        printf("\n");
    }
    return 0;
}
