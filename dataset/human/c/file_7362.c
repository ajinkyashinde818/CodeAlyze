#include <stdio.h>

int main(void)
{
    int i,j,x;
    int a[10000];

    for(i=1;;i++){
        scanf("%d",&x);

        if(x==0){
            break;
        }

    a[i]=x;
    }

    for(j=1;j<i;j++){
        printf("Case %d: %d\n",j,a[j]);
    }

    return 0;
}
