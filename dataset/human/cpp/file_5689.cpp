#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <cstring>

using namespace std;

long long g(long long n) {
  return 1LL << __builtin_ctz(~n);
}

int trie[100001][2];
bool accept[100001];
int pt = 1;

long long f(int u, long long l) {
  if (u == -1) return g(l);
  if (accept[u]) return 0;
  return f(trie[u][0], l - 1) ^ f(trie[u][1], l - 1);
}

int main() {
  int n;
  long long l;
  cin >> n >> l;

  memset(trie, -1, sizeof(trie));

  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;

    int u = 0;
    for (char c : s) {
      c -= '0';
      if (trie[u][c] == -1) {
        trie[u][c] = pt++;
      }
      u = trie[u][c];
    }
    accept[u] = true;
  }

  if (f(0, l) != 0) {
    cout << "Alice" << endl;
  } else {
    cout << "Bob" << endl;
  }
}
