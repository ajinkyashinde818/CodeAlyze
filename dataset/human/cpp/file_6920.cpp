#include <bits/stdc++.h>
using namespace std;

void Main()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        m[a[i]]++;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[n-1-i];
        m[b[n-1-i]]++;
    }
    for (auto i: m) {
        if (i.second > n) {
            cout << "No" << endl;
            return;
        }
    }
    cout << "Yes" << endl;
    for (int i = 0; i < n; i++)
    {
        while (a[i] == b[i]) {
            int r = rand() % n;
            if (a[r] != b[i] && b[r] != b[i]) {
                swap(b[i], b[r]);
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (i != 0) cout << " ";
        cout << b[i];
    }
    cout << endl;
}

int main(int argc, char **argv)
{
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    Main();
    return 0;
}
