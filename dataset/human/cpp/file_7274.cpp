#include <algorithm>
#include <cctype>
#include <cmath>
#include <iostream>
#include <queue>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#include <set>
#include <numeric>

using namespace std;


class ListNode {
public:
    int val;
    ListNode *next;
    ListNode(int val) {
        this->val = val;
        this->next = NULL;
    }
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};



int main() {
  int n; cin >> n;
  vector<int> vi(n);
  for (int i = 0; i < n; ++i) cin >> vi[i];
  long long sum = 0LL;
  for (int num : vi) sum += num;
  long long left = vi[0];
  long long res = abs(sum - left - left);
  for (int i = 1; i + 1 < n; ++i) {
    left += vi[i];
    long long tmp = abs(sum - left - left);
    res = min(res, tmp);
  }
  cout << res << endl;
  return 0;
}
