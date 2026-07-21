#include <iostream>

using namespace std;

const int kMaxN = 200001;

int a[kMaxN], b[kMaxN], c[kMaxN], d[kMaxN];
int n, x;

bool C() {
  for (int i = 1; i <= n; i++) {
    if (c[a[i]] + d[a[i]] > n) {
      return 0;
    }
  }
  for (int i = 1, j = 0; i <= n; i++) {
    for (; i < n && a[i + 1] == a[i]; i++) {
    }
    for (j = max(j, i + 1); c[a[i]]; j++) {
      if (b[(j - 1) % n + 1]) {
        c[b[(j - 1) % n + 1]]++;
      }
      b[(j - 1) % n + 1] = a[i];
      c[a[i]]--;
    }
  }
  for (int i = 1, j = 1; i <= n; i++) {
    if (!b[i]) {
      for (; !c[j]; j++) {
      }
      b[i] = j;
      c[j]--;
    }
  }
  return 1;
}

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    d[a[i]]++;
  }
  for (int i = 1; i <= n; i++) {
    cin >> x;
    c[x]++;
  }
  if (C()) {
    cout << "Yes" << endl;
    for (int i = 1; i <= n; i++) {
      cout << b[i] << " ";
    }
  } else {
    cout << "No";
  }
  return 0;
}
