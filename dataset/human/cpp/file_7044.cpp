#include<set>
#include<map>
#include<queue>
#include<stack>
#include<cmath>
#include<cstdio>
#include<vector>
#include<string>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<unordered_map>
#define fi first
#define se second
#define debug printf(" I am here\n");
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
const ll INF=0x3f3f3f3f3f3f3f3f;
const int maxn=2e5+5,inf=0x3f3f3f3f;
const double eps=1e-10;
int n,a[maxn],b[maxn];
int vis[maxn],ma1,ma2;
signed main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
//        vis[a[i]]++;
//        ma1=max(ma1,vis[a[i]]);
    }
//    memset(vis,0,sizeof(vis));
    for(int i=1;i<=n;i++){
        scanf("%d",&b[i]);
//        vis[b[i]]++;
//        ma2=max(ma2,vis[b[i]]);
    }
    reverse(b+1,b+1+n);
    int pos=1;
    for(int i=1;i<=n;i++){
        if(a[i]==b[i]){
            for(;pos<=n;pos++){
                if(b[pos]!=a[i]&&b[i]!=a[pos]){
                    swap(b[i],b[pos]);
                    break;
                }
            }
        }
    }
//    cout<<pos<<endl;
    if(pos>=n+1){
        printf("No\n");
    }else{
        printf("Yes\n");
        for(int i=1;i<=n;i++){
            printf("%d%c",b[i],i==n?'\n':' ');
        }
    }
//    if(ma1+ma2>n){
//        printf("No\n");
//    }else{
//        printf("Yes\n");
//        do{
//            bool flag=1;
//            for(int i=1;i<=n;i++){
//                if(a[i]==b[i]){
//                    flag=0;
//                    break;
//                }
//            }
//            if(flag){
//                for(int i=1;i<=n;i++){
//                    printf("%d%c",b[i],i==n?'\n':' ');
//                }
//                break;
//            }
//        }while(next_permutation(b+1,b+1+n));
//    }
    return 0;
}
