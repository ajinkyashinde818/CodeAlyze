#include <stdio.h>
#include <string>
#include <cstring>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <list>
#include <iterator>
#include <assert.h>
#pragma warning(disable:4996) 
 
typedef long long ll;
#define MIN(a, b) ((a)>(b)? (b): (a))
#define MAX(a, b) ((a)<(b)? (b): (a))
#define LINF 9223300000000000000
#define INF 2140000000
const long long MOD = 1000000007;
using namespace std;


char str[200005];

int main(int argc, char* argv[])
{
    int n;
    scanf("%d", &n);
    scanf("%s", str);

    int cntadd=0, cntsub=0;
    vector<int> cnt(n*2+1);
    int i;
    for(i=0; i<n*2; i++) {
        int tmp = (str[i]=='B'? 1: 0);
        if(cnt[i]%2==tmp) {
            cnt[i+1]=cnt[i]-1;
            cntsub++;
            if(cnt[i+1]<0) {
                printf("0\n"); return 0;
            }
        }
        else {
            cnt[i+1]=cnt[i]+1;
            cntadd++;
        }
    }
    if(cntadd!=n || cntsub!=n) {
        printf("0\n"); return 0;
    }

    ll ans=1;
    cntadd=0;
    for(i=1; i<=n*2; i++) {
        if(cnt[i]>cnt[i-1]) {
            ans = ans * (n-cntadd) %MOD;
            cntadd++;
        }
        else {
            ans = ans * cnt[i-1] %MOD;
        }
    }
    printf("%lld\n", ans);

    return 0;
}
