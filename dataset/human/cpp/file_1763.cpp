#include<iostream>
#include<algorithm>
using namespace std;
int p[300000], n, m;
pair<int, int>x[300000];
int main() {
    cin >> n >> m; for (int i = 1; i <= n; i++) { p[i] = i; }
    for (int i = 0; i < m; i++) { int r; cin >> r; p[r] = -i; }
    for (int i = 1; i <= n; i++) { x[i] = make_pair(p[i], i); }
    sort(x + 1, x + n + 1);
    for (int i = 1; i <= n; i++) { cout << x[i].second << endl; }
    return 0;
}
