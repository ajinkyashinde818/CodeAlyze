#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, R;
    cin >> N >> R;
    int innerRating = 100 * (10 - N);
    int displayRating;
    if (N >= 10) {
        displayRating = R;
    } else {
        displayRating = R + innerRating;
    }
    cout << displayRating << endl;
    return 0;
}
