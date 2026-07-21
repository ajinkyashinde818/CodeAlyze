#include <stdio.h>
int main(void)
{
        int i,N,K,P;

        scanf("%d",&N);

        int a[N];

        for(i=0; i<N; i++){
                scanf("%d %d",&K,&P);
                a[i]=K%P;
                if(K%P==0)
                        a[i]=P;
        }

        for(i=0; i<N; i++)
                printf("%d\n",a[i]);

        return 0;
}
