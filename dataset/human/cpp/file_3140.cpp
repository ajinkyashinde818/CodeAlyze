#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
int n;
int arr[N] ;
long long memo[N][2];

long long solve (int i , bool flipped) {
    if (i == n)
        return 0;

    long long &ret = memo[i][flipped];
    if (~ret)
        return ret;

    int cur = flipped ? -arr[i] : arr[i];
    int ncur = -cur;
    ret = solve(i + 1 , 0) + cur;
    if (i != n - 1)
        ret = max(ret , solve(i + 1 , 1) + ncur);
    return ret;
}

int main() {
    scanf("%d" , &n);
    for (int i = 0 ;i < n ;i++)
        scanf("%d" , arr + i);

    memset(memo , -1 , sizeof memo);
    printf("%lld" , solve(0 , 0));
}
