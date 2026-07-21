#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int64_t> cards(n);
    for (int i = 0; i < n; i += 1) {
        cin >> cards[i];
        if (i > 0) {
            cards[i] += cards[i - 1];
        }
    }

    int64_t res = abs(2 * cards[0] - cards[n - 1]);
    for (int i = 1; i + 1 < n; i += 1) {
        auto x = cards[i];
        auto y = cards[n - 1] - cards[i];
        res = min(res, abs(x - y));
    }

    cout << res << "\n";
    return 0;
}
