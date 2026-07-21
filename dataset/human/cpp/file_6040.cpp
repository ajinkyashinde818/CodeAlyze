#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef pair<long long, long long> sushi_t;

int
main()
{
    long long n, c;
    cin >> n >> c;
    vector<sushi_t> xv(n);
    for (int i = 0; i < n; i++) {
        long long x, v;
        cin >> x >> v;
        xv[i] = make_pair(x, v);
    }
    sort(xv.begin(), xv.end());

    // no turn
    vector<long long> acc(n + 1), acct(n + 1);
    acc[0] = 0;
    acct[0] = 0;
    long long prev_x = 0;
    for (int i = 0; i < n; i++) {
        acc[i + 1] = acc[i] + (prev_x - get<0>(xv[i])) + get<1>(xv[i]);
        acct[i + 1] = acct[i] + (prev_x - get<0>(xv[i])) * 2 + get<1>(xv[i]);
        prev_x = get<0>(xv[i]);
    }
    vector<long long> dec(n + 1), dect(n + 1);
    dec[0] = 0;
    dect[0] = 0;
    prev_x = 0;
    for (int i = 0; i < n; i++) {
        dec[i + 1] = dec[i] + (prev_x - (c - get<0>(xv[n - i - 1]))) +
            get<1>(xv[n - i - 1]);
        dect[i + 1] = dect[i] + (prev_x - (c - get<0>(xv[n - i - 1]))) * 2 +
            get<1>(xv[n - i - 1]);
        prev_x = c - get<0>(xv[n - i - 1]);
    }
    long long ans = 0;
    for (int i = 0; i < n + 1; i++) {
        if (acc[i] > ans)
            ans = acc[i];
        if (dec[i] > ans)
            ans = dec[i];
    }

    // turn
    long long maxdec = 0;
    for (int i = n; i > 0; i--) {
        if (maxdec < dec[n - i])
            maxdec = dec[n - i];
        long long tmp = acct[i] + max(maxdec, (long long)0);
        if (tmp > ans)
            ans = tmp;
    }
    long long maxacc = 0;
    for (int i = n; i > 0; i--) {
        if (maxacc < acc[n - i])
            maxacc = acc[n - i];
        long long tmp = dect[i] + max(maxacc, (long long)0);
        if (tmp > ans)
            ans = tmp;
    }

    cout << ans << endl;
}
