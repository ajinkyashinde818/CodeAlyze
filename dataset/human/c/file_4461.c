#include<stdio.h>
int main(void)
{
    int i,n,d1,d2,cnt,flg;
    scanf("%d",&n);
    cnt=0; flg=0;
    for(i=0;i<n;i++){
        scanf("%d%d",&d1,&d2);
        if(d1==d2) cnt++;
        else cnt=0;
        if(cnt==3) flg=1;
    }
    if(flg==1) printf("Yes\n");
    else printf("No\n");
    return 0;
}
