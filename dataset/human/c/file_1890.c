#include <stdio.h>
#include <stdlib.h>

int main(){
        int n, n2,ans=0;
        scanf("%d",&n);
        int *cursin,*tmp,*tmp2;
        cursin = (int *)malloc(sizeof(int)*n);
        tmp = (int *)malloc(sizeof(int)*n);
        tmp2 = (int *)malloc(sizeof(int)*n);

        for(int i=0;i<n;i++){
                scanf("%d",&n2);
                tmp[i]=n2;
        }
        for(int i=0;i<n;i++){
                scanf("%d",&n2);
                cursin[i]=n2;
        }
        for(int i=0;i<n-1;i++){
                scanf("%d",&n2);
                tmp2[i]=n2;
        }

        for(int i=0;i<n;i++){
                n2=tmp[i];
                ans+=cursin[n2-1];
                if(n2==tmp[i-1]+1&&i)ans+=tmp2[n2-2];
        }

        printf("%d\n",ans);

        return 0;
}
