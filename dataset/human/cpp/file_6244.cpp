#include <iostream>
#include <vector>
#include <string.h>
#include <stack>
#include <queue>
#include <algorithm>
#include <climits>
#include <cmath>
#include <map>
#include <set>
#include <assert.h>
#include <numeric>
#define REP(i,n) for(ll i=0;i<(n);i++)
#define MOD 1000000007
#define pb push_back
#define int long long
#ifdef int
const long long INF = LLONG_MAX / 10;
#else
const int INF = 1010101010;
#endif
using namespace std;
typedef long long ll;
typedef vector<int> vint;
typedef vector<vector<ll> > mat;
typedef pair<int, int> P;
//typedef pair<double, double> P;
const int dx[9] = {-1, 0, 0, 1, -1, -1, 1, 1, 0};
const int dy[9] = {0, -1, 1, 0, -1, 1, -1, 1, 0};

struct SegmentTree
{
private:
    int n;
    vector<int> node;
 
public:
    //元配列v(vector)をセグメント木で表現する
    SegmentTree(vector<int> v)
    {
        //最下段のノード数は元配列のサイズ以上になる最小の２冪→これをnとおく
        //セグメント木全体で必要なノード数は2n-1である
        int sz = v.size();
        n = 1;
        while (n < sz) n *= 2;
        node.resize(2 * n - 1, INF);
 
        //最下段に値を入れたあとに、下の段から埋めていく
        //値を埋めるときは自分の２つの子を見ればいい
        REP(i,sz) node[i+(n-1)] = v[i];
        for (int i=n-2; i>=0; i--) {
            //★セグ木の処理を書き換えるときはここを書き換える
            node[i] = min(node[2*i+1], node[2*i+2]);
        }
    }
 
    void update(int x, int val)
    {
        //最下段のノードにアクセスする
        x += n - 1;
 
        //最下段のノードを更新したら、あとは親に登って更新していく
        node[x] = val;
        while (x > 0) {
            //x=0でないなら親がある
            x = (x - 1) / 2;
            node[x] = min(node[2*x+1], node[2*x+2]);
        }
    }
 
    //要求区間[a,b)の要素の最小値を答える
    //k:=自分がいるノードのインデックス
    //対象区間は[l,r)にあたる
    int getmin(int a, int b, int k = 0, int l = 0, int r = -1)
    {
        //最初に呼び出されたときの対象区間は[0,n)
        if (r < 0) r = n;
 
        //要求区間と対象区間が交わらない→答えに影響を与えない値を返す
        //★セグ木の機能によって変える
        if (r <= a || b <= l) return INF;
 
        //要求区間が対象区間を完全に被覆→対象区間を答えの計算に使う
        if (a <= l && r <= b) return node[k];
 
        //要求区間が対象区間の一部を被覆→子について探索を行う
        //左の子をvl、右の子をvrとしている
        //新しい対象区間は現在の対象区間を半分にしたもの
        int vl = getmin(a, b, 2 * k + 1, l, (l + r) / 2);
        int vr = getmin(a, b, 2 * k + 2, (l + r) / 2, r);
        return min(vl, vr);
    }
};

int N, C;
int x[101010], v[101010];
 
signed main()
{
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> N >> C;
  REP(i,N) cin >> x[i] >> v[i];

  int ans1 = 0; //時計回り折り返さない
  int nowv1 = 0;
  REP(i,N) {
    nowv1 += v[i];
    ans1 = max(ans1, nowv1 - x[i]);
  }
  //cout << "ans1 = " << ans1 << endl;

  int ans2 = 0; //反時計回り折り返さない
  int nowv2 = 0;
  for (int i=N-1; i>=0; i--) {
    nowv2 += v[i];
    ans2 = max(ans2, nowv2 - (C - x[i]));
  }
  //cout << "ans2 = " << ans2 << endl;

  //時計回り折り返す
  //反時計回りの各点までの最大値
  int tmpans1 = 0;
  int nowv3 = 0;
  vector<int> a(N, INF);
  SegmentTree st(a);
  for (int i=N-1; i>=0; i--) {
    nowv3 += v[i];
    tmpans1 = max(tmpans1, nowv3 - (C - x[i]));
    // tmpans1 = max(tmpans1, nowv3);
    st.update((N-1)-i, -tmpans1);
  }
  int ans3 = 0;
  int nowv4 = 0;
  for (int i=0; i<N; i++) {
    nowv4 += v[i];
    int back = nowv4 - 2 * x[i];
    ans3 = max(ans3, back - st.getmin(0, N-i-2+1));
  }
  //cout << "ans3 = " << ans3 << endl;


  //反時計回り折り返す
  int tmpans2 = 0;
  int nowv5 = 0;
  vector<int> b(N, INF);
  SegmentTree st2(b);
  for (int i=0; i<N; i++) {
    nowv5 += v[i];
    tmpans2 = max(tmpans2, nowv5 - x[i]);
    // tmpans2 = max(tmpans2, nowv5);
    st2.update(i, -tmpans2);
  }
  int ans4 = 0;
  int nowv6 = 0;
  for (int i=N-1; i>=0; i--) {
    nowv6 += v[i];
    int forward = nowv6 - 2 * (C - x[i]);
    if (i == 0) {
      continue;
    } else {
      ans4 = max(ans4, forward - st2.getmin(0, i));
    }
  }
  //cout << "ans4 = " << ans4 << endl;

  cout << max(max(ans1, ans2), max(ans3, ans4)) << endl;
}
