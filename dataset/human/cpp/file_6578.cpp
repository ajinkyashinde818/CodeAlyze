#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int max_n=200005;
const int mod=1e9+7;
int n;
char s[max_n];
int a[max_n];
int main(){
    scanf("%d %s",&n,s+1);
    for(int i=1;i<=n*2;i++)a[i]=s[i]!='W';
    int ans=1,c=0;
    for(int i=1;i<=n*2;i++){
        if(a[i]!=c%2)c++;
        else{
            ans=1ll*ans*c%mod;
            c--;
            if(c<0){
                printf("0\n");
                return 0;
            }
        }
    }
    if(c!=0)ans=0;
    for(int i=1;i<=n;i++)ans=1ll*ans*i%mod;
    printf("%d\n",ans);
    return 0;
}
