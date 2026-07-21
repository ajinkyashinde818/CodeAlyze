#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,k=2,s=1;
vector<int>v[N];
int main()
{
    scanf("%d",&n);
    v[1].push_back(1);
    v[2].push_back(1);
    while(s<n)
    {
        for(int i=s+1,j=1;i<=s+k;i++,j++)
        {
            v[k+1].push_back(i);
            v[j].push_back(i);
        }
        s+=k;
        k++;
    }
    if(s>n) printf("No\n");
    else
    {
        printf("Yes\n");
        printf("%d\n",k);
        for(int i=1;i<=k;i++)
        {
            printf("%d",v[i].size());
            for(int j=0;j<v[i].size();j++)
                printf(" %d",v[i][j]);
            printf("\n");
        }
    }
}
