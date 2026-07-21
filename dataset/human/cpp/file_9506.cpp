#include <iostream>
#include <queue>
#include <set>
#include <algorithm>
#include <string>
#include <list>
using namespace std;

int state[51][51];
int temp[51][51];

int main(void){
  int N, M;
  cin >> N >> M;
  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      char c;
      cin >> c;
      state[j][i] = (c=='.')?0:1;
    }
  }
  for(int i = 0; i < M; i++){
    for(int j = 0; j < M; j++){
      char c;
      cin >> c;
      temp[j][i] = (c=='.')?0:1;
    }
  }

  bool isOK = false;
  for(int i = 0; i <= N - M; i++){
    for(int j = 0; j <= N - M; j++){
      bool flag = true;

      for(int k = 0; k < M; k++){
        for(int l = 0; l < M; l++){
          int nx = j+l;
          int ny = i+k;
          if(state[nx][ny] == temp[l][k])flag = true;
          else{
            flag = false;
            break;
          }
        }
        if(flag == false)break;
      }
      if(flag == true)isOK = true;
      if(isOK == true)break;
    }
    if(isOK == true)break;
  }
  cout << ((isOK)?"Yes":"No") << endl;
}
