#include<stdio.h>

int main(void)
{
int A,B,K,C,p,q,kotae,i;

        scanf("%d%d%d",&A,&B,&K);

        if(A>B) C=A;
        else C=B;

        for(i=C; i>0; i--){
           p=A%i;
           q=B%i;
                if((p==0) && (q==0)){
                        kotae++;
                if(K==kotae){ printf("%d\n",i);
        return 0;}
        }
}

        return 0;
}
