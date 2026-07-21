#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
/*
int a[200010];
int n;
long long ans;

int main(){
    cin>>n;
    for(int i=1;i<=n;i++)
        scanf("%d",a+i);
    sort(a+1,a+n+1);
    ans=0;
    if(n%2){
        for(int i=1;i<=(n-3)/2;i++)
            ans+=2*(a[n-i+1]-a[i]);
        ans+=a[(n+3)/2]-a[(n-1)/2];
        ans+=max(a[(n+3)/2]-a[(n+1)/2],a[(n+1)/2]-a[(n-1)/2]);
    }else{
        for(int i=1;i<=n/2-1;i++)
            ans+=2*(a[n-i+1]-a[i]);
        ans+=a[n/2+1]-a[n/2];
    }
    cout<<ans<<endl;
    return 0;
}
*/

int s[1000][1000];
int n;
int k;
int main(){
    cin>>n;
    int m=2;
    bool flag=false;
    s[1][1]=1;
    k=1;
    while(k<100000){
        for(int i=1;i<=m-1;i++,k++)
            s[i][m-1]=s[m][i]=k;
        if(k-1==n){
            puts("Yes");
            printf("%d\n",m);
            for(int i=1;i<=m;i++){
                printf("%d ",m-1);
                for(int j=1;j<=m-1;j++)
                    printf("%d ",s[i][j]);
                putchar('\n');
            }
            flag=true;
        }
        m++;
    }
    if(!flag)
        puts("No");
    return 0;
}
