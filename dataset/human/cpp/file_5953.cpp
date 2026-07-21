#include <iostream>

using namespace std;
using ll = long long;

int main()
{
    int n;
    ll c;
    cin >> n >> c;
    ll *x = new ll[n];
    int *v = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> x[i];
        cin >> v[i];
    }

    ll prev;
    ll next;

    ll *r = new ll[n];
    prev = v[0] - x[0];
    r[0] = prev;
    ll tmp = r[0];
    ll *r2 = new ll[n];
    r2[0] = prev - x[0];
    ll tmp2 = r2[0];
    for (int i = 1; i < n; i++) {
        next = prev + v[i] - x[i] + x[i-1];
        if (tmp < next) {
            r[i] = next;
            tmp = next;
            if (tmp2 < next - x[i]) {
                r2[i] = next - x[i];
                tmp2 = next - x[i];
            }
        }
        else {
            r[i] = tmp;
            r2[i] = tmp2;
        }
        prev = next;
    }
    
    ll *l = new ll[n];
    prev = v[n-1] - c + x[n-1];
    l[n-1] = prev;
    tmp = l[n-1];
    ll *l2 = new ll[n];
    l2[n-1] = prev - c + x[n-1];
    tmp2 = l2[n-1];
    for (int i = n-2; i >= 0; i--) {
        next = prev + v[i] + x[i] - x[i+1];
        if (tmp < next) {
            l[i] = next;
            tmp = next;
            if (tmp2 < next - c + x[i]) {
                l2[i] = next - c + x[i];
                tmp2 = next - c + x[i];
            }
        }
        else {
            l[i] = tmp;
            l2[i] = tmp2;
        }
        prev = next;
    }


    ll max = 0;
    if (max < r[n-1]) max = r[n-1];
    if (max < l[0]) max = l[0];

    for (int i = 1; i < n; i++) {
        ll t = r2[i - 1] + l[i];
        if (t > max) max = t;
    }
    for (int i = n-2; i >= 0; i--) {
        ll t = l2[i+1] + r[i];
        if (t > max) max = t;
    }

    cout << max << endl;

    return 0;
}
