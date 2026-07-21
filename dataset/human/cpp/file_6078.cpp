#include <bits/stdc++.h>

using namespace std;

class SegmentTree {
public:
  SegmentTree(const vector<long long> &a) : n(a.size()) {
    int size = 2 * pow(2.0, floor(log2(double(n))) + 1);
    rmq.assign(size, 0);
    Build(a, 1, 0, n);
  }
  long long Query(int ql, int qr) {
    return Query(1, 0, n, ql, qr);
  }
private:
  void Build(const vector<long long> &a, int id, int l, int r) {
    if (l + 1 == r) {
      rmq[id] = a[l];
    } else {
      int mid = (l + r) / 2;
      Build(a, 2 * id, l, mid);
      Build(a, 2 * id + 1, mid, r);
      rmq[id] = max(rmq[2 * id], rmq[2 * id + 1]);
    }
  }
  long long Query(int id, int l, int r, int ql, int qr) {
    if (l == ql && r == qr) {
      return rmq[id];
    }
    int mid = (l + r) / 2;
    if (qr <= mid) {
      return Query(2 * id, l, mid, ql, qr);
    } else if (ql >= mid) {
      return Query(2 * id + 1, mid, r, ql, qr);
    }
    return max(Query(2 * id, l, mid, ql, mid), Query(2 * id + 1, mid, r, mid, qr));
  }
  int n;
  vector<long long> rmq;
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n;
  long long c;
  cin >> n >> c;

  vector<pair<long long, long long>> sushi(n);
  for (int i = 0; i < n; ++i) {
    cin >> sushi[i].first >> sushi[i].second;
  }

  long long max_diff = 0;

  vector<long long> left_cum(n), left_diff(n);
  left_cum[0] = sushi[0].second;
  for (int i = 1; i < n; ++i) {
    left_cum[i] = left_cum[i-1] + sushi[i].second;
  }
  for (int i = 0; i < n; ++i) {
    left_diff[i] = left_cum[i] - sushi[i].first;
    max_diff = max(max_diff, left_diff[i]);
  }

  vector<long long> right_cum(n), right_diff(n);
  right_cum[n-1] = sushi[n-1].second;
  for (int i = n - 2; i >= 0; --i) {
    right_cum[i] = right_cum[i+1] + sushi[i].second;
  }
  for (int i = n - 1; i >= 0; --i) {
    right_diff[i] = right_cum[i] - c + sushi[i].first;
    max_diff = max(max_diff, right_diff[i]);
  }

  SegmentTree left_st(left_diff), right_st(right_diff);
  for (int i = 0; i < n - 1; ++i) {
    max_diff = max(max_diff, left_diff[i] + right_st.Query(i + 1, n) - sushi[i].first);
  }
  for (int i = n - 1; i > 0; --i) {
    max_diff = max(max_diff, right_diff[i] + left_st.Query(0, i) - c + sushi[i].first);
  }

  cout << fixed << max_diff << endl;

  return 0;
}
