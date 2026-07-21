#include <bits/stdc++.h>
using namespace std;
using Int = long long;
int PREP = (cin.tie(nullptr), ios::sync_with_stdio(false), cout << fixed << setprecision(12), 0);
//int SEGV = getenv("D") || (exit(system("D= SEGFAULT_SIGNALS=all catchsegv ./prog.exe") >> 8), 0);
int main() {
    int N; cin >> N;
    vector<int> A(N), B(N);
    for (auto &a : A) cin >> a;
    for (auto &b : B) cin >> b;
    map<int, int> Ma, Mb;
    for (auto a : A) Ma[a]++;
    for (auto b : B) Mb[b]++;
    set<pair<int, int>> Sa, Sb;
    vector<pair<int, int>> ans;
    for (auto pa : Ma) Sa.emplace(-pa.second, pa.first);
    for (auto pb : Mb) Sb.emplace(-pb.second, -pb.first);
    bool bans = true;
    while (!Sb.empty()) {
        auto [acnt, anum] = *begin(Sa);
        auto [bcnt, bnum] = *begin(Sb);
        Sb.erase(begin(Sb));
        acnt *= -1, bcnt *= -1, bnum *= -1;
        if (bcnt != 1) Sb.emplace(-(bcnt - 1), -bnum);
        if (anum != bnum) {
            ans.emplace_back(anum, bnum);
            Sa.erase(begin(Sa));
            if (acnt != 1) Sa.emplace(-(acnt - 1), anum);
        } else {
            if (Sa.size() == 1) {
                bans = false;
                break;
            }
            auto [acnt2, anum2] = *next(begin(Sa));
            ans.emplace_back(anum2, bnum);
            Sa.erase(next(begin(Sa)));
            acnt2 *= -1;
            if (acnt2 != 1) Sa.emplace(-(acnt2 - 1), anum2);
        }
    }
    if (bans == false) {
        cout << "No\n";
    } else {
        cout << "Yes\n";
        sort(begin(ans), end(ans));
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i].second << " \n"[i + 1 == ans.size()];
        }
    }
    return 0;
}
