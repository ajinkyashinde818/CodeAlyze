#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const double eps=1e-6,pi=acos(-1);
const int N=2e5+5,M=1e9+7,SEGM=4*N,OO=0x3f3f3f3f;
int t,n,m,k;
int a[N];
int b[N];

int main(){
    //freopen("myfile.txt","w",stdout);
    scanf("%d",&n);
    for(int i=0;i<n;++i)
        scanf("%d",a+i);
    for(int i=n-1;i>-1;--i)
        scanf("%d",b+i);
    int l=n,r=-1;
    for(int i=0;i<n;++i){
        if(a[i]==b[i]){
            l=i;
            break;
        }
    }
    for(int i=n-1;i>-1;--i){
        if(a[i]==b[i]){
            r=i;
            break;
        }
    }
    for(int i=0;i<n;++i)
        if(l<=r&&b[l]!=a[i]&&b[l]!=b[i])
            swap(b[i],b[l++]);
    if(l<=r){
        printf("No\n");
    }else{
        printf("Yes\n");
        for(int i=0;i<n;++i)
            printf("%d%c",b[i]," \n"[i+1==n]);
    }
    return 0;
}
