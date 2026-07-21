#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <climits>
#include <cassert>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <string>
#include <list>
#include <bitset>
#include <vector>
using namespace std;

#define I64d_OJ

//#ifdef I64d_OJ
//#define LL __int64
//#endif // I64d_OJ
#ifdef I64d_OJ
#define LL long long
#endif // I64d_OJ

typedef unsigned LL ULL;
typedef unsigned uint;
typedef pair<int,int> pii;
typedef pair<double,double> pdd;
typedef pair<LL,LL> pLL;
typedef vector<int> vi;

inline LL read(){
    LL x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-') f=-f; ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0'; ch=getchar();}
    return x*f;
}

#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
#define ls rt<<1
#define rs rt<<1|1
#define MID(a,b) (((LL)(a)+(LL)(b))>>1)
#define absx(a) ((a)<0?-(a):(a))
#define MK(a,b) make_pair(a,b)
#define PB(a) push_back(a)
#define lowbit(x) ((x)&-(x))

template< typename T >
inline void Max(T &a,T &b){if(a<b) a=b;}
template< typename T>
inline void Min(T &a,T &b){if(a>b) a=b;}

const double pi=(double)acos(-1.0);
const double eps=(double)1e-10;
const int INF = (int) 0x3f3f3f3f;
const int MOD = (int) 1e9+7;
const int MAXN =(int) 1e6+10;
const int MAXM = (int) 1e6+10;
const int sigma_size = (int) 26;

///--------------------START-------------------------
int N;
vector<int> ANS[MAXN];

void work(){
    scanf("%d",&N);
    int i,ok=0;
    for(i=1;i*(i+1)<=N*2;i++){
        if(i*(i+1)==N*2){
            ok=1; break;
        }
    }
    if(!ok) printf("No\n");
    else{
        printf("Yes\n%d\n",i+1);
        int cur=1;
        for(int id=1;id<i+1;id++){
            for(int j=1;j<=i-id+1;j++){
                ANS[id].push_back(cur);
                ANS[id+j].push_back(cur);
                cur++;
            }
        }
        for(int id=1;id<=i+1;id++){
            printf("%d",ANS[id].size());
            for(int j=0;j<ANS[id].size();j++){
                printf(" %d",ANS[id][j]);
            }
            printf("\n");
        }
    }
}

///--------------------END-------------------------
int main(){
#ifdef NNever
//freopen("data.in","r",stdin);
///freopen("out.txt","w",stdout);
#endif // NNever
    work();
    return 0;
}
