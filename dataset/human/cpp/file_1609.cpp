#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int n, k;
vector<int> vec[500];

int main() {
    scanf("%d",&n);
    for (k=1;k*(k-1)/2<n;k++);
    if (k*(k-1)/2==n) {
        printf("Yes\n%d\n",k);
        int i, j, p = 1;
        for (i=0;i<k;i++) {
            for (j=i+1;j<k;j++) {
                vec[i].push_back(p);
                vec[j].push_back(p);
                p++;
            }
        }
        for (i=0;i<k;i++) {
            printf("%d ",vec[i].size());
            for (int &v : vec[i]) printf("%d ",v);
            printf("\n");
        }
    }
    else printf("No\n");

    return 0;
}
