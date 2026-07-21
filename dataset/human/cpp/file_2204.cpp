#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;

int64_t a[100'000];

int main()
{
    int n;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    sort(a, a + n);

    int negidx = 0;
    for (int i = 0; i < n; i++)
    {
        negidx = i;
        if (a[i] >= 0)
        {
            break;
        }
    }

    int64_t nsum = accumulate(a, a + negidx, 0LL);
    int64_t psum = accumulate(a + negidx, a + n, 0LL);
    int64_t s = psum - nsum;
    if (negidx % 2 == 1)
    {
        s -= a[negidx] - a[negidx - 1];
        int64_t med = a[negidx] + a[negidx - 1];
        s += max(med, -med);
    }

    cout << s << endl;

    return 0;
}
