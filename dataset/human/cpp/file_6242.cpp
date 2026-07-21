#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void make_vs(int N, vector<pair<ll,ll>> const &xv, vector<ll> &vs) {
    ll tmp = 0;
    for (int i = 0; i < N; i++) {
        tmp += xv.at(i).second;
        vs.at(i) = tmp - xv.at(i).first;
    }
}

void make_vspmpos(int N, vector<ll> const &vs, vector<ll> &vspmpos) {
    ll tmp = vs.at(0);
    int curmax = 0;
    for (int i = 0; i < N; i++) {
        if (tmp < vs.at(i)) {
            curmax = i;
            tmp = vs.at(i);
        }
        vspmpos.at(i) = curmax;
    }
}

void make_table(int N, vector<pair<ll,ll>> const &xv, vector<ll> &vs, vector<ll> &vspmpos) {
    make_vs(N, xv, vs);
    make_vspmpos(N, vs, vspmpos);
}

ll calc(int N, vector<pair<ll, ll>> const &xv, vector<ll> const &vs, vector<ll> const &revvs, vector<ll> const &revvspmpos) {
    ll opt = 0;
    for (int right = -1; right < N; right++) {
        int left = right < N-1 ? revvspmpos.at(N - 2 - right) : -1;

        ll got = 0;
        if (right != -1) got = vs.at(right);
        ll will_get = 0;
        if (left != -1)  will_get = (right == -1 ? 0 : -xv.at(right).first) + revvs.at(left);
        opt = max(opt, got + max(0ll, will_get));
    }
    return opt;
}

int main() {
    int N;
    ll C;
    cin >> N >> C;
    vector<pair<ll,ll>> xv(N);
    for (int i = 0; i < N; i++) cin >> xv.at(i).first >> xv.at(i).second;

    sort(xv.begin(), xv.end());
    vector<ll> vs(N), vspmpos(N);
    make_table(N, xv, vs, vspmpos);

    vector<pair<ll,ll>> revxv(xv);
    for (auto &x: revxv) x.first = C - x.first;
    reverse(revxv.begin(), revxv.end());
    vector<ll> revvs(N), revvspmpos(N);
    make_table(N, revxv, revvs, revvspmpos);

    ll opt = max(calc(N, xv, vs, revvs, revvspmpos), calc(N, revxv, revvs, vs, vspmpos));

    cout << opt << endl;

    return 0;
}
