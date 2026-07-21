#include <stdio.h>
#include <limits.h>

int main() {
    int n;
    scanf("%d",&n);

    int ma,mi,maxdis;
    maxdis=(-1)*INT_MAX;
    int r;
    int i;
    for(i=0;i<n;i++) {
        scanf("%d",&r);
        if(!i)mi=r;
        if(i==1)ma=r;
        if(ma<r)ma=r;
        if(i&&maxdis<r-mi) {
            maxdis=r-mi;
        }
        if(mi>r)mi=r;
    }
    printf("%d\n",maxdis);
    return 0;
}
