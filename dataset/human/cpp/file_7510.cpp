#include <iostream>
#include <vector>
using namespace std;

using ll = long long;

int main() {
    int N;
    cin >> N;
    vector<int> cards(N);

    ll nusuke_sum = 0;
    ll arai_sum   = 0;
    for (auto& card : cards) {
        cin >> card;
        nusuke_sum += card;
    }
    nusuke_sum -= cards.back();
    arai_sum += cards.back();
    ll min = abs(nusuke_sum - arai_sum);
    for (ll i = cards.size() - 2; i > 0; --i) {
        nusuke_sum -= cards[i];
        arai_sum   += cards[i];
        const ll result = abs(nusuke_sum - arai_sum);
        if (result < min) min = result;
    }

    cout << min << endl;
    return 0;
}
