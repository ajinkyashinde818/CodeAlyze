#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <vector>
#include <sstream>
using namespace std;

typedef long long LL;
#define lowbit(x) ((x)&(-x))
#define INF 0x3f3f3f3f
#define memset(a,b) memset(a,b,sizeof(a))
#define	GE() printf(">----------\n")
#define	IN() freopen("in.txt","r",stdin)
#define	OUT() freopen("out.txt","w",stdout)
const int mod=1e9+7;
const LL inf=0x3f3f3f3f3f3f3f3f;
const double pi=acos(-1.0);
const double eps=1e-8;
const int maxn=200005;

int n;
int data[maxn];

int main() {
    while(cin>>n){
        LL x=0, y=0;
        for(int i=0;i<n;i++){
            cin>>data[i];
            y+=data[i];
        }
        LL ans=inf;
        for(int i=0;i<n-1;i++){
            y-=data[i];
            x+=data[i];
            ans=min(ans, abs(x-y));
        }
        cout<<ans<<endl;
    }
    return 0;
}
