#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef pair<int ,int> pii;
typedef pair<ll, ll> pll;
typedef double rl;
typedef pii int2;
typedef tuple<int, int, int>           int3;
typedef tuple<int, int, int, int>      int4;
typedef tuple<int, int, int, int, int> int5;

typedef pll ll2;
typedef tuple<ll, ll, ll>         ll3;
typedef tuple<ll, ll, ll, ll>     ll4;
typedef tuple<ll, ll, ll, ll, ll> ll5;

#define g0(x) get<0>(x)
#define g1(x) get<1>(x)
#define g2(x) get<2>(x)
#define g3(x) get<3>(x)
#define g4(x) get<4>(x)

typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<ll> vll;
typedef vector<pll> vll_ll;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
typedef vector<vll> vvll;
typedef vector<vll_ll> vvll_ll;

#define pb push_back
#define mp make_pair
#define eb emplace_back
#define xx first
#define yy second

#define FOR(i,N) for(int i=0; i<N; i++)

#define popc __builtin_popcountll
// #define popc __builtin_popcount

template<typename A>
string to_string(A* ptr)
{
    stringstream ss; ss << "0x" << std::setw(16) << std::setfill ('0') << std::hex << (uint64_t)(uintptr_t)ptr;
    return ss.str();
}

string to_string(char c)
{
    return ((string)"'"+c)+ "'";
}

template <typename A, typename B>
string to_string(pair<A, B> p);

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p);

template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p);

string to_string(const string& s) {
  return '"' + s + '"';
}

string to_string(const char* s) {
  return to_string((string) s);
}

string to_string(bool b) {
  return (b ? "true" : "false");
}

string to_string(vector<bool> v) {
  bool first = true;
  string res = "{";
  for (int i = 0; i < static_cast<int>(v.size()); i++) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(v[i]);
  }
  res += "}";
  return res;
}

template <size_t N>
string to_string(bitset<N> v) {
  string res = "";
  for (size_t i = 0; i < N; i++) {
    res += static_cast<char>('0' + v[i]);
  }
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

void debug_out() { cerr << endl; }

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}

#if !ONLINE_JUDGE && 1
#define dbg(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define dbg(...) 42
#endif

const int MX=2e5+99;
int A[MX], B[MX], N;
int ans[MX];

int cntA[MX], cntB[MX];
int AL[MX], AR[MX];

bool ok()
{
    for(int i=0; i<N; i++)
    {
        assert(ans[i]!=-42);
        if(A[i]==ans[i]) return false;
    }
    return true;
}

inline int my_rand(int K)
{
    ui res=rand();
    res=(res<<16)^rand();
    return res%K;
}

bool solve()
{
    for(int i=1; i<=N; i++) cntA[i]=cntB[i]=0;

    for(int i=0; i<N; i++)
    {
        AR[A[i]]=i;
        cntA[A[i]]++;
        cntB[B[i]]++;
    }
    for(int i=N-1; i>=0; i--) AL[A[i]]=i;


    for(int i=1; i<=N; i++)
    {
        if(cntA[i]+cntB[i]>N) return false;
    }
    //set<int> free_pos;
    //for(int i=0; i<N; i++) free_pos.insert(i);

    /*
    for(int i=1; i<=N; i++)
    {
        int cc=cntB[i];

    }
    */

    for(int i=0; i<N; i++) ans[i]=B[i];
    set<pii> S_bad;

    for(int i=0; i<N; i++) if(ans[i]==A[i]) S_bad.insert({ans[i], i});

    while(true)
    {
        if(S_bad.empty())
        {
            assert(ok());
            return true;
        }

        auto itL=S_bad.begin();
        auto itR=S_bad.end(); --itR;
        auto [ans1, idx1]=*itL;
        auto [ans2, idx2]=*itR;

        if(ans1!=ans2)
        {
            S_bad.erase(itL); S_bad.erase(itR);
            swap(ans[idx1], ans[idx2]);

            assert(ans[idx1]!=A[idx1]);
            assert(ans[idx2]!=A[idx2]);
        }
        else
        {
            //assert(false);
            //int val=ans1;

            vector<int> pos_bad, pos_good;
            for(int i=0; i<N; i++)
            {
                if(A[i]==ans[i])
                {
                    assert(ans[i]==ans1); pos_bad.pb(i);
                }
                else if(A[i]!=ans1 && ans[i]!=ans1) pos_good.pb(i);
            }

            assert(pos_good.size()>=pos_bad.size());
            for(int i=0; i<(int)pos_bad.size(); i++)
            {
                swap(ans[pos_bad[i]], ans[pos_good[i]]);
            }

            assert(ok());
            return true;
        }
    }

    /*
    multiset<int> SB(B, B+N);
    for(int i=0; i<N; i++)
    {
        auto it=SB.upper_bound(A[i]);
        if(it==SB.end())
        {
            it=SB.begin();
            ans[i]=*it;
            SB.erase(it);
        }
        else
        {
            ans[i]=*it;
            SB.erase(it);
        }

        assert(ans[i]!=A[i]);
    }
    //*/

    /*
    vector<pii> freq_vals(N);
    for(int i=1; i<=N; i++) freq_vals[i-1]={cntA[i]+cntB[i], i};
    sort(freq_vals.begin(), freq_vals.end(), greater<pii>());

    while(true)
    {
        for(int i=0; i<N; i++) ans[i]=-42;

        vector<int> pos(N); for(int i=0; i<N; i++) pos[i]=i;
        int sz=N;

        for(auto [AB, val]: freq_vals)
        {
            int cc=cntB[val];
            if(cc==0) continue;

            for(int i=0; i<cc; i++)
            {
                int idx=my_rand(sz);

            }
        }

        if(ok()) break;
    }
    */

    return true;
}

int main()
{
#if !ONLINE_JUDGE && 1
    freopen("F.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
#if 0
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
#endif

#if !ONLINE_JUDGE && 1
    int TTT;
    cin >> TTT;
#else
    int TTT=1;
#endif
    for(int ttt=0; ttt<TTT; ttt++)
    {
        cin >> N;
        for(int i=0; i<N; i++) cin >> A[i];
        for(int i=0; i<N; i++) cin >> B[i];

        if(solve())
        {
            cout << "Yes" << endl;
            for(int i=0; i<N; i++) cout << ans[i] << ' ';
            cout << endl;
        }
        else cout << "No" << endl;
    }

    return 0;
}
