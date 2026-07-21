#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, r;
    cin >> n >> r;

    if (n >= 10)
        cout << r << "\n";
    else
        cout << r + 100 * (10 - n) << "\n";

    return 0;
}
