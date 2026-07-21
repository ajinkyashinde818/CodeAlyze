#include <stdio.h>
int max2(int x,int y){
    if(x>y){
        return x;
    }else{
        return y;
    }
}

int main(void){
    int A,B,C,D;
    int x,y;
    scanf("%d %d %d %d",&A,&B,&C,&D);

    x=A*B;
    y=C*D;

    printf("%d\n",max2(x,y));

    return 0;
}
