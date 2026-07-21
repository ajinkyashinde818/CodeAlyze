#include<bits/stdc++.h>

using namespace std;

struct UnionFind
{
  vector< int > data;

  UnionFind(int sz)
  {
    data.assign(sz, -1);
  }

  bool unite(int x, int y)
  {
    x = find(x), y = find(y);
    if(x == y) return (false);
    if(data[x] > data[y]) swap(x, y);
    data[x] += data[y];
    data[y] = x;
    return (true);
  }

  int find(int k)
  {
    if(data[k] < 0) return (k);
    return (data[k] = find(data[k]));
  }

  int size(int k)
  {
    return (-data[find(k)]);
  }
};

int main()
{
  int N, A[100001], B[100001];

  cin >> N;
  for(int i = 0; i < N; i++) cin >> A[i];
  for(int i = 0; i < N; i++) cin >> B[i];

  A[N] = B[N] = 0;
  for(int i = 0; i < N; i++) A[N] ^= A[i];
  for(int i = 0; i < N; i++) B[N] ^= B[i];

  if(multiset< int >(A, A + N + 1) != multiset< int >(B, B + N + 1)) {
    cout << -1 << endl;
    return (0);
  }


  int ret = 0;

  if(A[N] != B[N]) {
    ++ret;
    for(int i = 0; i < N; i++) {
      if(A[i] != B[i] && B[i] == A[N]) {
        swap(A[i], A[N]);
        break;
      }
    }
  }
  vector< int > es;
  for(int i = 0; i < N; i++) {
    if(A[i] != B[i]) {
      ++ret;
      es.emplace_back(A[i]);
    }
  }
  sort(begin(es), end(es));
  es.erase(unique(begin(es), end(es)), end(es));
  UnionFind uf(es.size());
  for(int i = 0; i < N; i++) {
    if(A[i] == B[i]) continue;
    uf.unite(lower_bound(begin(es), end(es), A[i]) - begin(es),
             lower_bound(begin(es), end(es), B[i]) - begin(es));
  }
  for(int i = 0; i < es.size(); i++) {
    ret += i == uf.find(i);
  }
  for(int i = 0; i < N; i++) {
    if(A[i] != B[i] && B[i] == A[N]) {
      --ret;
      break;
    }
  }
  cout << ret << endl;
}
