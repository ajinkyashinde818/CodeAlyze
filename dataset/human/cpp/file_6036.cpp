#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
const ll MOD = 1000000007;

template <typename T>
class SegmentTree{
private:
    int n;
    vector<T> dat;
public:
    void init(int n_){
        n = 1;
        while(n < n_) n *= 2;
        dat.assign(2*n-1, -1);
    }
    // k: index(0-indexed), a: value
    void update(int k, T a){
        k += n-1;
        dat[k] = a;
        while(k>0){
            k = (k-1)/2;
            dat[k] = max(dat[k*2+1], dat[k*2+2]);
        }
    }
    // query(a, b) =>  minimum in [a,b]
    T query(int a, int b){
        return _query(a, b, 0, 0, n-1);
    }
    // dat[k] is minimum in [l,r]
    T _query(int a, int b, int k, int l, int r){
        if(r<a || b<l) return -1;
        if(a<=l&&r<=b){
            return dat[k];
        }else{
            T vl = _query(a, b, k*2+1, l, (l+r)/2);
            T vr = _query(a, b, k*2+2, (l+r)/2+1, r);
            return max(vl, vr);
        }
    }
};

ll x[100002];
ll v[100002];
ll N, C;

ll solve(){
    ll ret = 0;
    SegmentTree<ll> seg;
    seg.init(N + 1);
    seg.update(0, 0);

    ll v_sum = 0;
    for(int i=0;i<N;i++){
        v_sum += v[i];
        ret = max(ret, v_sum - x[i]);
        seg.update(i + 1, v_sum - x[i]);
    }

    v_sum = 0;
    for(int i=N-1;i>=1;i--){
        v_sum += v[i];
        ret = max(ret, v_sum - 2 * (C - x[i]) + seg.query(0, i));
    }

    return ret;
}

int main(){
    cin >> N >> C;

    for(int i=0;i<N;i++){
        cin >> x[i] >> v[i];
    }

    ll ans = solve();
    for(int i=0;i<N;i++){
        x[i] = C - x[i];
    }
    for(int i=0;i<N/2;i++){
        swap(x[i], x[N - 1 - i]);
        swap(v[i], v[N - 1 - i]);
    }
    ans = max(ans, solve());
    cout << ans << endl;

    return 0;
}
