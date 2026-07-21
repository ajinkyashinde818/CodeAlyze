#include <bits/stdc++.h>
using namespace std;

int A[100005];

bool cmp(int a, int b)
{
    return abs(a) < abs(b);
}

int main() {
    
    ios::sync_with_stdio(0);
    cin.tie(NULL), cout.tie(NULL);

    int N;
    cin >> N;

    for(int i=1; i<=N; i++)
        cin >> A[i];

    sort(A+1, A+1+N, cmp);

    int neg = 0;
    long long ans = 0;

    for(int i=1; i<=N; i++)
        neg += (A[i] < 0);

    ans += (neg % 2 ? - abs(A[1]) : abs(A[1]));

    for(int i=2; i<=N; i++)
        ans += abs(A[i]);

    cout << ans << "\n";
    return 0;
}
