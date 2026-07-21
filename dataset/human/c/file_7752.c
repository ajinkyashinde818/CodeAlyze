#include <stdio.h>
int main(void){
        int n;
        int i;

        scanf("%d",&n);

        int k[n],p[n],w[i];

    for(i=0; i<n; i++){

                scanf("%d %d",&k[i],&p[i]);

                if(k[i]%p[i]==0)
                        w[i]=p[i];

                else
                        w[i]=k[i]%p[i];

                }

        for(i=0; i<n; i++){

                printf("%d\n",w[i]);

        }

        return 0;

}
