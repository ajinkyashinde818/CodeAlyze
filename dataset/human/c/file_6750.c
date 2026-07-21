#include<stdio.h>
int main()
{
    int a[30000]={0},b[30000]={0},flg[30000]={0};
    int i,j,k;
    int seito,list,cnt=0;
    while(scanf("%d",&seito)!=EOF)
    {
        scanf("%d",&list);
        if(seito==0&&list==0)break;
        flg[1]=1;
        for(i=1;i<=list;i++)
        {
            scanf("%d %d",&a[i],&b[i]);
        }
        for(j=1;j<100;j++)
        {
        for(k=1;k<=15000;k++)
        {
            if(flg[a[k]]==1)flg[b[k]]=2;
            else if(flg[a[k]]==2&&flg[b[k]]!=2)flg[b[k]]=3;
        }
        for(k=1;k<=15000;k++)
        {
            if(flg[b[k]]==1&&a[k]!=1)flg[a[k]]=2;
            else if(flg[b[k]]==2&&a[k]!=1&&flg[a[k]]!=2)flg[a[k]]=3;
        }
        }
        for(i=2;i<20000;i++)
        {
            if(flg[i]==2||flg[i]==3)
            {
                //printf("%d\n",i);
                cnt++;
            }
        }
        printf("%d\n",cnt);
        cnt=0;
        for(i=0;i<30000;i++)
        {
            a[i]=0;
            b[i]=0;
            flg[i]=0;
        }
    }
    return 0;
}
