#include<iostream>
using namespace std;

int main() {
  long N, C;
  cin >> N >> C;
  long X[N], V[N];
  for (int i = 0; i < N; i++) cin >> X[i] >> V[i];
  long v_sum_cw = 0, v_sum_ccw = 0, cw[N], ccw[N], max_cw[N], max_ccw[N];
  for (int i = 0; i < N; i++) {
    v_sum_cw += V[i]; v_sum_ccw += V[N - i - 1];
    cw[i] = v_sum_cw - X[i];
    ccw[N - 1 - i] = v_sum_ccw - (C - X[N - 1 - i]);
    if (i) {
      max_cw[i] = max(max_cw[i-1], cw[i]);
      max_ccw[N - 1 - i] = max(max_ccw[N - i], ccw[N - 1 - i]);
    } else {
      max_cw[i] = cw[i];
      max_ccw[N - 1 - i] = ccw[N - 1 - i];
    }
  }
  long max_nutrition = max(0L, max(max_cw[N - 1], max_ccw[0]));
  for (int i = 0; i < N - 1; i++) {
    max_nutrition = max(max_nutrition, cw[i] - X[i] + max_ccw[i + 1]);
    max_nutrition = max(max_nutrition,
                        ccw[N - 1 - i] - (C - X[N - 1 - i]) + max_cw[N - i - 2]);
  }
  cout << max_nutrition << endl;
}
