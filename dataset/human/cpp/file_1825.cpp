#include <bits/stdc++.h>

using namespace std;


int main()
{
  int N, M, E[200000];
  bool used[200001] = {};

  scanf("%d %d", &N, &M);
  for(int i = 0; i < M; i++) {
    scanf("%d", E + i);
  }
  for(int i = M - 1; i >= 0; i--) {
    if(used[E[i]]++) continue;
    printf("%d\n", E[i]);
  }
  for(int i = 1; i <= N; i++) {
    if(used[i]++) continue;
    printf("%d\n", i);
  }
}
