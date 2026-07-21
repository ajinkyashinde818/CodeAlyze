#include<stdio.h>

int main(void)
{
        int A,B,K;
        int i,j;

        scanf("%d%d%d",&A,&B,&K);



        if(A>B)i=B;
        else i=A;



        for(j=0;j<K;i--){
                if(A%i==0 && B%i==0)j++;
        }






        printf("%d\n",i+1);

        return 0;
}
