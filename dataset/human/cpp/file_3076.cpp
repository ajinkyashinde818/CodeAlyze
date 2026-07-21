#include <bits/stdc++.h>
#include <cassert>
using namespace std;

size_t N;

class solver {
public:
  solver(size_t size_)
      : cur(0), bests(vector<vector<long>>(size_ + 1, vector<long>(2, 0))),
        num_seq(vector<long>(size_ + 1, 0)) {
    bests[0][0] = 0;
    bests[0][1] = LONG_MIN;
  }

  void push_num(long num) {
    num_seq[cur + 1] = num;
    bests[cur + 1][0] = get_best(cur, 0);
    bests[cur + 1][1] = get_best(cur, 1);
    cur++;
  }

  long get_total(void) { return bests[bests.size() - 1][0]; }

protected:
  long get_best(size_t cur_, long flag) {
    if (cur_ == 0) {
      if (flag == 0)
        return num_seq[1];
      else
        return -num_seq[1];
    }

    if (flag == 0)
      return max(bests[cur][0] + num_seq[cur + 1],
                 bests[cur][1] - num_seq[cur + 1]);
    else
      return max(bests[cur][0] - num_seq[cur + 1],
                 bests[cur][1] + num_seq[cur + 1]);
  }

  size_t cur;
  vector<vector<long>> bests;
  vector<long> num_seq;
};

int main(void) {
  cin >> N;

  solver sol = solver(N);
  long num;

  for (long i = 0; i < N; i++) {
    cin >> num;
    sol.push_num(num);
  }

  cout << sol.get_total() << "\n";
  return 0;
}
