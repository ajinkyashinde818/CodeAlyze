#include <bits/stdc++.h>

using namespace std;

bool IncludeImage(const vector<string> &a, const vector<string> &b) {
    const int n = a.size();
    const int m = b.size();

    for (int i = 0; i + m <= n; ++i) {
        for (int j = 0; j + m <= n; ++j) {
            bool in_image = true;

            for (int k = 0; k < m; ++k) {
                if (a[i + k].substr(j, m) != b[k]) {
                    in_image = false;
                    break;
                }
            }

            if (in_image) return true;
        }
    }

    return false;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, m;

    cin >> n >> m;

    vector<string> a(n), b(m);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i < m; ++i)
        cin >> b[i];

    if (IncludeImage(a, b))
        cout << "Yes\n";
    else
        cout << "No\n";

    return 0;
}
