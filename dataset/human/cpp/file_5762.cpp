#include <bits/stdc++.h>
using namespace std;

int n;
long long l;
int trie[100005][2];
int tn;

long long grundy;

long long get_grundy(long long x) {
  long long answer = 1;
  while (answer <= x) {
    if (answer * 2 > x || x % (answer * 2) > 0) {
      return answer;
    }
    answer *= 2;
  }
}

void insert(string s) {
  int idx = 0;
  for (int i = 0; i < s.size(); i++) {
    int next = s[i] - '0';
    if (trie[idx][next] == -1) {
      trie[idx][next] = tn++;
    }
    idx = trie[idx][next];
  }
}

int main() {
  memset(trie, -1, sizeof(trie));
  tn = 1;
  cin >> n >> l;
  for (int ni = 0; ni < n; ni++) {
    string s;
    cin >> s;
    insert(s);
  }
  grundy = 0;
  queue<pair<int, int>> q;
  q.push(make_pair(0, 0));
  while (!q.empty()) {
    auto top = q.front();
    int idx = top.first;
    int depth = top.second;
    q.pop();
    if (trie[idx][0] == -1 && trie[idx][1] != -1 || trie[idx][0] != -1 && trie[idx][1] == -1) {
      grundy ^= get_grundy(l - depth);
    }
    if (trie[idx][0] != -1) {
      q.push(make_pair(trie[idx][0], depth + 1));
    }
    if (trie[idx][1] != -1) {
      q.push(make_pair(trie[idx][1], depth + 1));
    }
  }
  if (grundy == 0) {
    cout << "Bob" << endl;
  } else {
    cout << "Alice" << endl;
  }
  return 0;
}
