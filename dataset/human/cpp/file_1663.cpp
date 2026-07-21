#include<bits/stdc++.h>
using namespace std;
int n;
vector<int> G[1005];
int main()
{
    scanf("%d",&n);
    int k = 1;
    while((k*(k-1)/2) < n) k++;
    if(k*(k-1)/2 != n){puts("No");return 0;}
    puts("Yes");cout<<k<<endl;
    int cnt = 0;
    for(int i = 1;i <= k;i++){
        for(int j = i + 1;j <= k;j++) {G[i].push_back(++cnt);G[j].push_back(cnt);}
    }
    for(int i = 1;i <= k;i++){
        printf("%d ",G[i].size());
        for(int j = 0;j < G[i].size();j++) printf("%d ",G[i][j]);
        printf("\n");
    }
    return 0;
}
