#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int MAXN=100010;
int r,g,b,n;
inline int read(){
    int f=1,x=0;
    char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') {x=x*10+ch-'0';ch=getchar();}
    return f*x;
}
ll ans;
int main(){
    r=read();g=read();b=read();n=read();
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            if((n-(i*r+j*g))%b==0&&n>=(i*r+j*g)){
                ans++;
                //cout<<i<<" "<<j<<endl;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
