#include <cstdio>
#include <vector>
#include <algorithm>

int main() {
  int nI;
  scanf("%d", &nI);
  std::vector<int> its(nI);
  for (int i = 0; i < nI; ++i) {
    scanf("%d", &its[i]);
  }
  std::vector<long long> maxSumIfOp(nI + 1);
  std::vector<long long> prefixMax(nI + 1);
  maxSumIfOp[2] = 1LL * -its[0] - its[1];
  prefixMax[2] = std::max(maxSumIfOp[2], 1LL * its[0] + its[1]);
  if (nI >= 3) {
    maxSumIfOp[3] = maxSumIfOp[2] + 2 * its[1] - its[2];
    maxSumIfOp[3] = std::max(maxSumIfOp[3], 1LL * its[0] - its[1] - its[2]);
    prefixMax[3] = std::max(prefixMax[2] + its[2], maxSumIfOp[3]);
  }
  for (int i = 4; i <= nI; ++i) {
    maxSumIfOp[i] = std::max(maxSumIfOp[i], maxSumIfOp[i - 1] + 2 * its[i - 2] - its[i - 1]);
    maxSumIfOp[i] = std::max(maxSumIfOp[i], prefixMax[i - 2] - its[i - 2] - its[i - 1]);
    prefixMax[i] = std::max(prefixMax[i - 1] + its[i - 1], maxSumIfOp[i]);
  }
  printf("%lld\n", prefixMax[nI]);
  return 0;
}
