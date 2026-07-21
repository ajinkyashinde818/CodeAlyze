#include <stdio.h>

int main(void)
{
        int n,i,s=0;
        scanf("%d",&n);
        int a[n],b[n],c[n-1];
        for(i=0;i<n;i++)
                scanf("%d",&a[i]);
        for(i=0;i<n;i++)
                scanf("%d",&b[i]);
        for(i=0;i<n-1;i++)
                scanf("%d",&c[i]);

        for(i=0;i<n;i++){
                s+=b[a[i]-1];
                if(i>0 && a[i]==a[i-1]+1) s+=c[a[i-1]-1];
        }
        printf("%d\n",s);
        return 0;
}
