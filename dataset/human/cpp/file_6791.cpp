#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <functional>
#include <utility>
using i64 = long long;

int main() {
    int n;
    std::cin >> n;

    std::vector<std::pair<int, int>> r(n + 1), s;
    std::vector<int> ca(n + 1), cb(n + 1);
    for (int i = 0; i < n; i++) {
        int a;
        std::cin >> a;
        ca[a]++;
        if (ca[a] == 1) r[a] = std::make_pair(i, i + 1);
        else r[a].second++;
    }
    for (int i = 0; i < n; i++) {
        int b;
        std::cin >> b;
        cb[b]++;
    }

    for (int i = 1; i <= n; i++) {
        const int t = ca[i] + cb[i];
        if (t > n) {
            std::cout << "No" << std::endl;
            return 0;
        }
        if (t) s.emplace_back(t, i);
    }

    std::sort(s.begin(), s.end(), std::greater<>());

    std::vector<int> ret(n);
    try {
        std::set<int> ss;
        for (int i = 0; i < n; i++) ss.insert(i);
        std::vector<int> ex;
        for (const auto [c, i] : s) {
            const int bb = cb[i];
            for (int j = r[i].first; j < r[i].second; j++) {
                auto it = ss.find(j);
                if (it != ss.end()) {
                    ex.push_back(*it);
                    ss.erase(it);
                }
            }
            for (int j = 0; j < bb; j++) {
                if (ss.empty()) throw 0;
                auto it = ss.begin();
                ret[*it] = i;
                ss.erase(*it);
            }
            for (const int j : ex) ss.insert(j);
            ex.clear();
        }
    } catch (...) {
        std::set<int> ss;
        for (int i = 0; i < n; i++) ss.insert(i);
        std::vector<int> ex;
        for (const auto [c, i] : s) {
            const int bb = cb[i];
            for (int j = r[i].first; j < r[i].second; j++) {
                auto it = ss.find(j);
                if (it != ss.end()) {
                    ex.push_back(*it);
                    ss.erase(it);
                }
            }
            for (int j = 0; j < bb; j++) {
                if (ss.empty()) throw 0;
                auto it = ss.rbegin();
                ret[*it] = i;
                ss.erase(*it);
            }
            for (const int j : ex) ss.insert(j);
            ex.clear();
        }
    }

    std::cout << "Yes\n";
    for (const int e : ret) std::cout << e << ' ';
    std::cout << std::endl;

    return 0;
}
