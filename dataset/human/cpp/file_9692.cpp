#include <bits/stdc++.h>

using namespace std;

int main()
{
  int N, M;
  char a[64][64], b[64][64];
  
  scanf("%d %d", &N, &M);
  
  for (int i = 0; i < N; i++) {
    scanf("%s", a[i]);
  }
  for (int i = 0; i < M; i++) {
    scanf("%s", b[i]);
  }
  
  bool ok = false;
  for (int i = 0; i <= N - M; i++) {
    for (int j = 0; j <= N - M; j++) {
      bool found = true;
      for (int k = 0; k < M; k++) {
        for (int l = 0; l < M; l++) {
          if (a[i + k][j + l] != b[k][l]) found = false;
        }
      }
      ok |= found;
    }
  } 
  
  printf("%s\n", ok ? "Yes" : "No");
}
