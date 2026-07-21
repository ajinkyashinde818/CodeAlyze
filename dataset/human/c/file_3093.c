#include <stdio.h>

int main(void) {
  int k, n;
  scanf("%d %d", &k, &n);
  int arr[n + 1];
  for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
  arr[n] = k + arr[0];

  int _max = 0, index = 0;
  for (int i = 0; i < n; i++) {
    int tmp = arr[i + 1] - arr[i];
    if (_max < tmp) {
      _max = tmp;
      index = i;
    }
  }

  int ans = k - _max < arr[index] + k - arr[index + 1] ? k - _max : arr[index] + k - arr[index + 1];
  printf("%d\n", ans);

  return 0;
}
