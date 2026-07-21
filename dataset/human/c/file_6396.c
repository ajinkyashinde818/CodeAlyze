#include <stdio.h>
int main(void){
    int n,i,t,small,dif,mv;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&t);
        if(i==0) small = t;
        dif = t-small;
        if(small>t)
        {
            small = t;
        }
        if(i==1) mv = dif;
        if(i>1)
        {
            if(mv<dif) mv = dif;
        }
    }
    printf("%d\n",mv);
}
