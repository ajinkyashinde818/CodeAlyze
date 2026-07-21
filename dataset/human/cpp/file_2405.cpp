#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<list>
#include<queue>
#include<deque>
#include<algorithm>
#include<numeric>
#include<utility>
#include<complex>
#include<memory>
#include<functional>
#include<cstring>

using namespace std;

#ifdef LDEBUG
#define debug(x) cout << #x << ":" << x << endl
#else
#define debug(...)
#endif

#define REP(i,n) for(int i=0; i<n; ++i)

typedef unsigned long long u64;
typedef long long i64;

int n;
int a[100005];

int main(){
        cin.tie(0);
        ios::sync_with_stdio(false);

        cin >> n;

        REP(i,n)
                cin >> a[i];

        int m = 1;
        REP(i,n)
                if (a[i] < 0) m *= -1;

        i64 r = 0;
        if (m == 1) {
                REP(i,n)
                        if(a[i] < 0)
                                a[i] *= -1;
                REP(i,n)
                        r += a[i];
        } else {
                REP(i,n)
                        if(a[i] < 0)
                                a[i] *= -1;
                sort(a, a+n);
                a[0] *= -1;

                REP(i,n)
                        r += a[i];
        }

        cout << r << endl;


        return 0;
}
