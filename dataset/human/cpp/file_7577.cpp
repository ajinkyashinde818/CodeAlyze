#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <vector>

using namespace std;

int N;
vector<long long> A;

int main() {
  scanf("%d", &N);
  long long ai;
  long long sum = 0;
  for (int i = 0; i < N; ++i) {
    scanf("%lld", &ai);
    sum += ai;
    A.push_back(ai);
  }
  long long snuke_nums = 0;
  vector<long long> Diffs;
  for (int i = 0; i < N - 1; ++i) {
    snuke_nums += A[i];
    long long raccoon_nums = sum - snuke_nums;
    Diffs.push_back(abs(snuke_nums - raccoon_nums));
  }
  vector<long long>::iterator iter = min_element(Diffs.begin(), Diffs.end());
  int target_index = distance(Diffs.begin(), iter);
  printf("%lld", Diffs[target_index]);
}
