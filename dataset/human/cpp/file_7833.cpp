#include <bits/stdc++.h>
#include<climits>

using namespace std;
int n;
long long int ar[200001];
long long int ans = LONG_MAX;
int main() {
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        scanf("%lld", &ar[i]);
        ar[i] += ar[i-1];
    }

    for (int i = 1; i < n; i++) {
        long int lsum = ar[i];
        long int rsum = ar[n] - lsum;
        if (abs(lsum-rsum) < ans)
            ans = abs(lsum-rsum);
    }
    printf("%lld\n", ans);

    //for (int i = 0; i <=n; i++)
    //    printf("%d ", ar[i]);


    return 0;
}
