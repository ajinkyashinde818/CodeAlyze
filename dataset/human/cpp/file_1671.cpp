#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5,M=8e2;
int us[M][M],cnt;
int main(){
    ios::sync_with_stdio(false);
    int n;cin>>n;
    if(n==1)printf("Yes\n2\n1 1\n1 1\n"),exit(0);
    if(n==2)printf("No\n"),exit(0);
    for(int i=1;i*(i-1)/2<=n;++i){
        if(i*(i-1)/2==n){
            printf("Yes\n%d\n",i);
            for(int j=1;j<=i;++j){
                for(int k=1;k<j;++k){
                    us[j][k]=us[k][j-1];
                }for(int k=j;k<i;++k)us[j][k]=++cnt;
            }
            for(int j=1;j<=i;++j){
                printf("%d ",i-1);
                for(int k=1;k<i;++k)printf("%d ",us[j][k]);
                printf("\n");
            }exit(0);
        }
    }printf("No\n");return 0;
}
