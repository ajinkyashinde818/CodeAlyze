#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long LL;
const int maxn=1e5+10;
vector<int> ans[maxn];
LL n;

void solve(int k) {
    int cur=1;
    puts("Yes");
    printf("%d\n", k);
    for (int i=1;i<=k;i++)
        for (int j=i+1;j<=k;j++) {
            ans[i].push_back(cur);
            ans[j].push_back(cur);
            cur++;
        }

    for (int i=1;i<=k;i++) {
        printf("%d ", (int)ans[i].size());
        for (auto j:ans[i]) printf("%d ", j);
        puts("");
    }
}

int main() {
    scanf("%lld",&n);
    bool f=false;
    for (int i=1;i<=1000;i++)
        if ((LL)i*(i-1)/2==n) {
            solve(i);
            f=true;
            break;
        }

    if (!f) puts("No");
    return 0;
}
