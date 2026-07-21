#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int R, G, B, N;
    cin >> R >> G >> B >> N;

    vector<int> rg;
    for (int r = 0; r * R <= N; ++r) {
        for (int g = 0; r * R + g * G <= N; ++g) {
            rg.push_back(N - r * R - g * G);
        }
    }

    sort(rg.begin(), rg.end());
    int count = 0;
    for (int b = 0; b * B <= N; ++b) {
        auto it =  upper_bound(rg.begin(), rg.end(), b * B) - lower_bound(rg.begin(), rg.end(), b * B);
        count += it;
    }

    cout << count << '\n';

    return 0;
}
