#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <deque>
#include <fstream>
#include <functional>
#include <iostream>
#include <istream>
#include <iterator>
#include <sstream>
#include <list>
#include <map>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#include <iomanip>
#define BR "\n"
#define REP(i,n) for(int (i)=0;(i)<(n);++(i))
#define ALL(cont) begin(cont),end(cont)
#define AS_MOD(a,b) ((((a) % (b) ) + (b)) % (b))
#define FEACH(it,cont) for(auto (it) = begin(cont); it!=end(cont);++it)
#define FEACHR(it,cont) for(auto (it) = rbegin(cont); it!=rend(cont);++it)
#define pb push_back
#define pob pop_back
#define fi first
#define se second
#define getll() ([](){ll s;scanf("%lld", &s);return s;})()
#define getld() ([](){ld s;scanf("%Lf", &s);return s;})()
#define prl(P) printf("%lld", P)
#define prd(P) printf("%.10Lf", P)
#define pr(P) printf(P)
#define MAX(V, T) V=max(V,T)

#define DumpArray(cont,from,to) for(int __i=from;__i<to;++__i) {cout<<"(" <<__i<<": " << cont[__i]<<")";} cout<<endl;

using namespace std;
typedef long long ll;
typedef long double ld;
int main() {
    int R,G,B,N;
    cin >> R >> G >> B >> N;
    int ans=0;
    for(int r=0;r*R<=N;++r) {
        for(int g=0;g*G<=N-r*R;++g) {
            if ((N-r*R-g*G)%B==0) {
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
