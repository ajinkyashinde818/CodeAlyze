#include <bits/stdc++.h>

template <class T>
void print(const T& a) {
    for (auto el : a) std::cout << el << " ";
    std::cout << std::endl;
}

std::deque<long long> cg[100100];

int main() {
    long long n;
    std::cin >> n;
    std::vector<long long> a(n + 1), b(n + 1);
    {
        std::map<long long, long long> cnt;
        long long x = 0;
        for (int i = 0; i < n; i++) {
            std::cin >> a[i];
            x ^= a[i];
            cnt[a[i]]++;
        }
        for (int i = 0; i < n; i++) {
            std::cin >> b[i];
            cnt[b[i]]--;
        }
        a[n] = x;
        cnt[x]++;
        for (auto& el : cnt) {
            if (el.second < 0) {
                std::cout << -1 << std::endl;
                return 0;
            }
            if (el.second > 0) x = el.first;
        }
        b[n] = x;
    }
    // print(a); print(b);
    {
        auto ca(a), cb(b);
        std::sort(ca.begin(), ca.end());
        ca.erase(std::unique(ca.begin(), ca.end()), ca.end());
        std::sort(cb.begin(), cb.end());
        cb.erase(std::unique(cb.begin(), cb.end()), cb.end());
        for (int i = 0; i <= n; i++) {
            a[i] = std::lower_bound(ca.begin(), ca.end(), a[i]) - ca.begin();
            b[i] = std::lower_bound(cb.begin(), cb.end(), b[i]) - cb.begin();
        }
    }
    
    // print(a); print(b);

    // std::vector<std::deque<long long>> cg(100010);
    std::set<long long> s;
    for (int i = 0; i <= n; i++) {
        if (a[i] != b[i]) {
            cg[a[i]].push_back(b[i]);
            s.insert(a[i]);
        }
    }

    auto ret = 0ll;
    while (!s.empty()) {
        // print(s);
        std::deque<long long> q;
        q.push_back(*s.begin());
        s.erase(s.begin());
        while (!q.empty()) {
            auto curr = *q.begin();
            if (curr == a[n]) ret--;
            ret += cg[curr].size();
            for (auto& to : cg[curr]) {
                if (s.find(to) != s.end()) {
                    q.push_back(to);
                    s.erase(s.find(to));
                }
            }
            q.pop_front();
        }
        ret++;
    }

    std::cout << ret - (a[n] == b[n] ? 0 : 1) << std::endl;

    return 0;
}
