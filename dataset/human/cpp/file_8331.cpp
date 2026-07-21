#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1000000007;

int main(){
  int N,M;
  cin >> N >> M;
  string A[N];
  string B[M];
  for(int i = 0; i < N; i++){
    cin >> A[i];
  }
  for(int i = 0; i < M; i++){
    cin >> B[i];
  }
  bool flag1 = false;
  for(int i = 0; i <= N - M; i++){
    for(int j = 0; j <= N - M; j++){
      bool flag = true;
      for(int x = 0; x < M; x++){
	for(int y = 0; y < M; y++){
	  if(A[i+x][j+y] != B[x][y]){
	    flag = false;
	  }
	}
      }
      if(flag == true){
	flag1 = true;
      }
    }
  }
  if(flag1){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
}
