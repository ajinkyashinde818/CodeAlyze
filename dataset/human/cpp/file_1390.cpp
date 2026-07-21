#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int ans;
int main()
{
    int R,G,B,N;
    scanf("%d %d %d %d",&R,&G,&B,&N);
    for(int i=0;R*i<=N;i++)
    {
        for(int j=0;G*j<=N;j++)
        {
            int k = N-R*i-G*j;
            if(k>=0 && k%B ==0 ) ans++;
        }
    }
    printf("%d",ans);
}
