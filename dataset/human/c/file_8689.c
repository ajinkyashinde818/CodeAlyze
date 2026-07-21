#include<stdio.h>

int main(void)
{
        int i,j;
        int n,tmp,kaisu;

        scanf("%d",&n);

        int a[n];

        for(i=0;i<n;i++)
                scanf("%d",&a[i]);

        kaisu = 0;
        tmp = a[0];
        for(i=1;i<n;i++){
                kaisu++;
                if(tmp==2){
                        printf("%d\n",kaisu);
                        return 0;
                }
                tmp = a[tmp-1];
        }

        printf("-1\n");
        return 0;
}
