#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int n,grundy[201][101],a,b,ans;
int dfs(int a,int b){
    if(grundy[a][b]!=-1){
        return grundy[a][b];
    }
    set<int> se;
    if(a>0)se.insert(dfs(a-1,b));
    if(b>0)se.insert(dfs(a+1,b-1));
    for(int i=1;i<=a&&i<=b;i++){
        se.insert(dfs(a,b-i));
    }
    int res=0;
    while(se.count(res)){
        res++;
    }
    return grundy[a][b]=res;
}
int main(void){
    cin>>n;
    for(int i=0;i<201;i++)for(int j=0;j<101;j++)grundy[i][j]=-1;
    grundy[0][0]=0;
    for(int i=0;i<n;i++){
        cin>>a>>b;
        ans^=dfs(a,b);
    }
    if(ans==0)cout<<1<<endl;
    else cout<<0<<endl;
}
