#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>

#include<vector>
using namespace std;
int qread()
{
    int ans=0;char c=getchar();
    while(c<'0' or c>'9') c=getchar();
    while(c>='0' and c<='9') ans=ans*10+c-'0',c=getchar();
    return ans;
}
void qwrite(int num)
{
    if(num>=10) qwrite(num/10);
    putchar('0'+num%10);
}
void qwriteln(int num) {qwrite(num);puts("");}

vector<int> ans[1000];
int main()
{
    int n;scanf("%d",&n);

    bool bk=0;
    for(int s1=1;s1<=1000;s1++)
    {
        if(s1*(s1+1)/2==n)
        {
            puts("Yes");bk=1;

            for(int t=1;t<=s1;t++) ans[1].push_back(t),ans[1+t].push_back(t);

            int now=s1;
            for(int a=2;a<=s1+1;a++)
            {
                for(int b=a+1;b<=s1+1;b++)
                {
                    now++;
                    ans[a].push_back(now);
                    ans[b].push_back(now);
                }
            }

            printf("%d\n",s1+1);
            for(int i=1;i<=s1+1;i++)
            {
                printf("%d ",ans[i].size());
                for(int t=0;t<(int)ans[i].size();t++) printf("%d ",ans[i][t]);
                puts("");
            }
            break;
        }
    }
    if(!bk) puts("No");
}
