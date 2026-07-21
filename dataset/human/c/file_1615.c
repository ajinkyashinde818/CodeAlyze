#include <stdio.h>

int main(void)
{
    char s[100001];
    scanf("%s",s);
    long int a=0;
    long int ans=0;
    while(s[a]!=NULL)
      a++;
    char ss[100001] = {};
    long int b=-1;
    for(long int p=0;p<a;p++)
    {
        if(s[p]!=0x78)
        {
            b++;
            ss[b]=s[p];
        }
    }
    if(ss[0]==0)
    {
        printf("0");
        return 0;
    }
    char sss[a];
    for(long int q=0;q<b+1;q++)
      sss[q]=ss[b-q];
    long int min=0;
    long int max=a-1;
    long int mincount=0;
    long int maxcount=0;
    long int check=8;
    long int t[a];
    long int aans=0;
    //printf("%s\n%s\n%s\n",s,ss,sss);
    for(long int u=0;u<b+1;u++)
    {
        if(ss[u]==sss[u])
          aans++;
    }
    if(aans!=b+1)
    {
        printf("-1");
        return 0;
    }
    else
    {
        for(long int r=0;r<a;r++)
        {
            if(s[r]==0x78)
              t[r]=0;
            else
              t[r]=1;
        }
        //for(int w=0;w<a;w++)printf("%d",t[w]);
        while(check!=0 && min<max)
        {
            check=0;
            while(t[min]!=1)
            {
                min++;
                mincount++;
            }
            while(t[max]!=1)
            {
                max--;
                maxcount++;
            }
            if(mincount>=maxcount)ans+=mincount-maxcount;
            else ans+=maxcount-mincount;
            mincount=0;
            maxcount=0;
            min++;
            max--;
            for(int y=min;y<max+1;y++)
            {
                check+=t[y];
            }
        }
    }
    printf("%ld",ans);
}
