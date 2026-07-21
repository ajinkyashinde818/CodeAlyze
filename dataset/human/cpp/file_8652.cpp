#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

long long MOD = 1000000000 + 7;
long long MAX = 1000000000000000000;

int main(){
  int N,M;
  cin >> N >> M;
  vector<string> v(N);
  vector<string> w(M);

  for(int i =0; i < N; i++){
    cin >> v[i];
  }
  for(int i =0; i < M; i++){
    cin >> w[i];
  }

  bool ans_flg = false;
  for(int i = 0; i < N-M+1; i++){
    for(int j = 0; j < N-M+1; j++){
      bool flg = true;
      // 1つでもfalseになれば、ijを更新する
      for(int k = 0; k < M; k++){
        for(int l = 0; l < M; l++){
          if(v[i+k][j+l] != w[k][l]){
            flg = false;
            break;
          }
        }
        if(!flg) break;
      }
      if(flg){
        ans_flg = true;
        break;
      }
      if(!flg){
        continue;
      }
    }
    if(ans_flg){
      break;
    }
  }

  cout << (ans_flg ? "Yes" : "No") << endl;
}
