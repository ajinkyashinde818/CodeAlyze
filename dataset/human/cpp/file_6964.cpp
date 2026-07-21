/*
lakshaygpt28
Lakshay Gupta
*/

#include <bits/stdc++.h>
using namespace std;

string to_string(char ch) {
    return "'" + string(1, ch) + "'";
}

string to_string(string s) {
    return '"' + s + '"';
}

string to_string(const char* s) {
    return to_string((string) s);
}

string to_string(bool b) {
    return (b ? "true" : "false");
}

template <typename A, typename B>
string to_string(pair<A, B> p) {
    return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p) {
    return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")";
}

template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p) {
    return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";
}

template <size_t N>
string to_string(bitset<N> v) {
    return v.to_string();
}

string to_string(vector<bool> v) {
    bool first = true;
    string res = "{";
    for (int i = 0; i < v.size(); ++i) {
        if (!first) {
            res += ", ";
        }
        first = false;
        res += to_string(v[i]);
    }
    res += "}";
    return res;
}

template <typename A>
string to_string(A v) {
    bool first = true;
    string res = "{";
    for (const auto &x : v) {
        if (!first) {
            res += ", ";
        }
        first = false;
        res += to_string(x);
    }
    res += "}";
    return res;
}

void debug_out() { cout << endl; }

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    cout << " " << to_string(H);
    debug_out(T...);
}

#ifndef ONLINE_JUDGE
#define debug(...) cout << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

const double PI = acos(-1);
const long long LINF = LLONG_MAX;
const int INF = INT_MAX, MOD = 1e9 + 7, N = 2e5 + 10;

int main() {
    ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int n;
    cin >> n;
    vector<int> a(n), b(n), cnta(n + 1), cntb(n + 1);
    vector<bool> vis(n);
    set<pair<int, int>> s;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        cnta[a[i]]++;
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        cntb[b[i]]++;
    }
    for (int i = 1; i <= n; i++) {
        if (n - cntb[i] < cnta[i]) {
            cout << "No\n";
            return 0;
        }
    }
    cout << "Yes\n";
    reverse(b.begin(), b.end());
    int val = 0;
    vector<int> c;
    for (int i = 0; i < n; i++) {
        if (a[i] == b[i]) {
            val = a[i];
            c.emplace_back(i);
        }
    }
    vector<int> d;
    for (int i = 0; i < n; i++) {
        if (a[i] != val and b[i] != val) {
            d.emplace_back(i);
        }
    }
    for (int i = 0; i < c.size(); i++) {
        swap(b[c[i]], b[d[i]]);
    }
    for (auto x : b) {
        cout << x << " ";
    }
    cout << "\n";
    return 0;
}
