#include <bits/stdc++.h>

int N;
const int MAX_N = 200005;
int as[MAX_N];
int ac[MAX_N], bcc[MAX_N];
std::vector<std::pair<int, int>> bccc;

int main() {
  scanf("%d", &N);
  for (int i = 0; i < N; ++i) {
    int v;
    scanf("%d", &v);
    as[i] = v;
    ac[v]++;
  }
  for (int i = 0; i < N; ++i) {
    int v;
    scanf("%d", &v);
    bcc[v]++;
  }
  for (int i = 0; i < MAX_N; ++i) {
    if (bcc[i]) bccc.push_back({i, bcc[i]});
  }
  bool doable = true;
  for (auto& kv: bccc) {
    if (kv.second + ac[kv.first] > N) {
      doable = false;
      break;
    }
  }
  if (!doable) {
    printf("No\n");
    return 0;
  }
  printf("Yes\n");
  std::vector<int> ans;
  auto eng = std::default_random_engine(12432);
  while (1) {
    auto bc = bccc;
    std::shuffle(bc.begin(), bc.end(), eng);
    ans.clear();
    int idx = 0, bidx = 0;
    while (bc.size()) {
      if (bc[bidx].first == as[idx]) {
        if (bc.size() == 1) break;
        bidx = (bidx + 1) % bc.size();
      }
      while (bc[bidx].second && as[idx] != bc[bidx].first) {
        idx++;
        bc[bidx].second--;
        ans.push_back(bc[bidx].first);
      }
      if (bc[bidx].second == 0) {
        std::swap(bc[bidx], bc.back());
        bc.pop_back();
        bidx = 0;
      }
    }
    if (ans.size() == N) break;
  }
  for (int i : ans) printf("%d ", i);
  printf("\n");
}
