//2019/9/28

#include <stdio.h>

int main (void) {
    int num,border,ans=0,temp,i;
    scanf("%d %d",&num,&border);
    for (i=0;i<num;i++) {
        scanf("%d",&temp);
        if (temp>=border) ans++;
    }
    printf("%d\n",ans);
    return 0;
}
