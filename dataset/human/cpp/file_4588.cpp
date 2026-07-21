#include <iostream>

using namespace std;

void resolve()
{
    int N, R;
    cin >> N >> R;
    int ans = (N >= 10) ? R : (R + 100 * (10 - N));
    cout << ans << endl;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    resolve();
    return 0;
}
