/**
 * Dont raise your voice, improve your argument.
 * --Desmond Tutu
 */

#include <bits/stdc++.h>
using namespace std;

const bool ready = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(12);
    return true;
}();

const double PI = acos(-1);
using ll= long long;
#define int ll
#define all(v) (v).begin(), (v).end()
#define fori(n) for(int i=0; i<int(n); i++)

#define cini(i) int i; cin>>i;
#define cins(s) string s; cin>>s;
#define cind(d) double d; cin>>d;
#define cinai(a,n) vi a(n); fori(n) { cin>>a[i]; }
#define cinas(s,n) vs s(n); fori(n) { cin>>s[i]; }
#define cinad(a,n) vd a(n); fori(n) { cin>>a[i]; }

using pii= pair<int, int>;
using pdd= pair<double, double>;
using vd= vector<double>;
using vb= vector<bool>;
using vi= vector<int>;
using vvi= vector<vi>;
using vs= vector<string>;

#define endl "\n"

const int INF=1e9;
void solve() {
    cini(n);

    vi a(n+1);
    vi aa(n);
    for(int i=0; i<n; i++) {
        cin>>aa[i];
        a[aa[i]]++;
    }

    vi b(n+1);
    vi bb(n);
    bool imp=false;
    for(int i=0; i<n; i++) {
        cin>>bb[i];
        b[bb[i]]++;

        if(a[bb[i]]+b[bb[i]]>n)
            imp=true;
    }

    if(imp) {
        cout<<"No"<<endl;
        return;
    }
    cout<<"Yes"<<endl;

    set<pii> q;
    vi cnt(n+1);
    for(int i=1; i<=n; i++) {
        cnt[i]=a[i]+b[i];

        if(b[i]>0)
            q.emplace(-cnt[i], i);
    }

    vi ans(n);
    for(int i=0; i<n; i++) {
        assert(q.size()>0);
        auto it=q.begin();
        if(aa[i]==it->second)
            it++;
        ans[i]=it->second;

        q.erase({-cnt[aa[i]], aa[i]});

        cnt[aa[i]]--;
        if(b[aa[i]]>0)
            q.emplace(-cnt[aa[i]], aa[i]);

        it=q.lower_bound({-cnt[ans[i]], ans[i]});
        assert(it!=q.end());
        q.erase(it);
        cnt[ans[i]]--;
        b[ans[i]]--;
        if(b[ans[i]]>0)
            q.emplace(-cnt[ans[i]], ans[i]);
    }

    for(int i=0; i<n; i++)
        cout<<ans[i]<<" ";
    cout<<endl;

}

signed main() {
    solve();
}

// FIRST THINK, THEN CODE
// DO NOT JUMP BETWEEN PROBLEMS
