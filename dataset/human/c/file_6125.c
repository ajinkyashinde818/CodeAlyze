#include <stdio.h>
#include <stdlib.h>

int main(){
    int n, maxv, minv, r, a;
    scanf("%d",&n);

    scanf("%d",&r);
    minv = r;
    for(a = 1; a < n; a++){
        scanf("%d",&r);
        if(a == 1) maxv = r - minv;
        maxv = maxv < (r-minv) ? (r-minv) : maxv;
        minv = minv > r ? r : minv;
    }

    printf("%d\n",maxv);
    return 0;
}
