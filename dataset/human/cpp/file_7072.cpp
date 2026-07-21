#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template <class T> using vec = vector<T>;
template <class T> using vvec = vector<vec<T>>;
template<class T> bool chmin(T& a,T b){if(a>b) {a = b; return true;} return false;}
template<class T> bool chmax(T& a,T b){if(a<b) {a = b; return true;} return false;}
#define all(x) (x).begin(),(y).end()
#define debug(x)  cerr << #x << " = " << (x) << endl;

using P = pair<int,int>;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    vec<int> A(N),B(N);
    vvec<int> pos(N);
    vec<int> cntA(N),cntB(N);
    for(int i=0;i<N;i++){
        cin >> A[i];
        A[i]--;
        cntA[A[i]]++;
        pos[A[i]].push_back(i);
    }
    for(auto& x:B){
        cin >> x;
        x--;
        cntB[x]++;
    }
    for(int i=0;i<N;i++){
        if(cntA[i]+cntB[i]>N){
            cout << "No\n";
            return 0;
        }
    }
    vec<int> idx(N);
    iota(idx.begin(),idx.end(),0);
    sort(idx.begin(),idx.end(),[&](int i,int j){
        return (cntA[i]+cntB[i]!=cntA[j]+cntB[j]? cntA[i]+cntB[i]>cntA[j]+cntB[j]:i>j);
    });
    vec<int> a;
    for(auto& i:idx){
        for(int j=0;j<cntA[i];j++){
            a.push_back(i);
        }
    }
    sort(idx.begin(),idx.end(),[&](int i,int j){
        return (cntA[i]+cntB[i]!=cntA[j]+cntB[j]? cntA[i]+cntB[i]>cntA[j]+cntB[j]:i>j);
    });
    vec<int> b;
    for(auto& i:idx){
        for(int j=0;j<cntB[i];j++){
            b.push_back(i);
        }
    }
    reverse(b.begin(),b.end());
    int l = 0;
    for(int i=0;i<N;i++) if(a[i]==b[i]){
        swap(b[l++],b[i]);
    }
    vec<int> ans(N);
    for(int i=0;i<N;i++){
        ans[pos[a[i]].back()] = b[i];
        pos[a[i]].pop_back();
    }
    cout << "Yes\n";
    for(int i=0;i<N;i++) cout << ans[i]+1 << (i!=N-1? " ":"\n");
}
