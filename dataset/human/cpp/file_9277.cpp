#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <bitset>
#include <cmath>
#include <cstdlib>
#include <cstdio>

using namespace std;

const long long INF = 100000000;
const long long MOD = 1000000007;


long long gcd(long long a,long long b){
  if(a<b){
    swap(a, b);
  }
  if(a%b==0)
    return b;
  return gcd(a % b, b);
}

int main()
{
  int N, M;
  cin >> N >> M;
  char A[N][N];
  char B[M][M];
  for (int i = 0; i < N;i++){
    for (int j = 0; j < N;j++)
      cin >> A[i][j];
  }
  for (int i = 0; i < M; i++)
  {
    for (int j = 0; j < M; j++)
      cin >> B[i][j];
  }
  bool ans = false;
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N;j++){
      if (j + M - 1 >= N or i + M - 1 >= N)
        continue;

      //一致しているか
      bool an = true;
      for (int a = 0; a < M;a++){
        for (int b = 0; b < M;b++){
          if (i + a < N && j + b < N){
            if (A[i + a][j + b] != B[a][b])
              an = false;
          }

        }
      }
      if(an)
        ans = true;
    }
  }

  if(ans)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}
