#include <bits/stdc++.h>

using namespace std;

struct Sushi
{
    int64_t x, v;
};

int main()
{
    int N;
    int64_t C;
    cin >> N >> C;

    vector<Sushi> s(N);

    for (int i = 0; i < N; ++i) {
        cin >> s[i].x >> s[i].v;
    }

    // Reflect `s` straight the circle's circumference.
    // Note that `s` must be sorted in increasing order.
    auto reflect = [C] (vector<Sushi> vs)
    {
        for (Sushi & s : vs) {
            s.x = C - s.x;
        }
        reverse(vs.begin(), vs.end());
        return vs;
    };

    // sbest[i] = if we are free to take any prefix of length i from s, what is the most we can gain?
    auto make_best = [N] (const vector<Sushi>& s)
    {
        assert (static_cast<int>(s.size()) == N);

        int64_t sum = 0;
        vector<int64_t> sbest(N);
        for (int i = 0; i < N; ++i) {
            sum += s[i].v;
            const int64_t now = sum - s[i].x;

            if (i > 0) {
                sbest[i] = max(now, sbest[i - 1]);
            } else {
                sbest[i] = now;
            }
        }
        return sbest;
    };

    // Case 1, he chooses a clockwise prefix and then walks out.
    auto straight = [&make_best] (const vector<Sushi>& s)
    {
        return make_best(s).back();
    };

    // Case 2, when he takes a prefix, walks back and then takes a suffix.
    auto around = [N, &make_best] (const vector<Sushi>& s, const vector<Sushi>& sref)
    {
        auto srefbest = make_best(sref);

        assert (static_cast<int>(s.size()) == N);
        assert (static_cast<int>(sref.size()) == N);
        assert (static_cast<int>(srefbest.size()) == N);

        int64_t best = 0;
        int64_t sum = 0;
        for (int i = 0; i + 1 < N; ++i) {
            sum += s[i].v;

            // Since the sref is ordered backward. we can take a prefix of `sref`
            // with a length at most N - i - 1.
            // That way, we avoid taking a sushi piece twice.
            const int64_t now = sum - 2 * s[i].x + srefbest[N - i - 2];
            if (now > best) {
                best = now;
            }
        }
        return best;
    };

    vector<Sushi> sref = reflect(s);

    int64_t best_case1 = max(
            straight(s), straight(sref));

    int64_t best_case2 = max(
            around(s, sref), around(sref, s));

    int64_t best = max(best_case1, best_case2);

    assert (best >= 0);
    cout << best << "\n";
    return 0;
}
