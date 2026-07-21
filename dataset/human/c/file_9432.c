#include <stdio.h>

int main(void)
{
        int n,d,x,i,j,c;

        scanf("%d%d%d",&n,&d,&x);

        int a[n];

        for(i=0;i<n;i++)
                scanf("%d",&a[i]);

        c=0;
        for(i=0;i<n;i++){
                for(j=0;a[i]*j+1<=d;j++){
                        c++;
                }
        }
        printf("%d\n",c+x);
        return 0;
}
