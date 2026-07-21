#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <stack>
#include <set>
#include <map>
typedef long long ll;
using namespace std;

int main(){
  int N;
  cin >> N;

  //x(x-1)/2 = Nとなるxが存在しなければ構築できない。
  int x = 2; //集合の数
  while(x * (x - 1) / 2 < N) x++;

  if(x * (x - 1) / 2 == N){
    cout << "Yes\n" << x << endl;
    //集合の要素数sz;
    int sz = 2 * N / x;
    int ans[x][sz];
    int ed = sz + 1; //端の数
    for(int i = 0; i < sz; i++){
      ans[0][i] = i + 1;
    }

    for(int i = 1; i < x; i++){
      for(int j = 0; j < sz; j++){
        if(j < i){
          ans[i][j] = ans[j][i - 1];
        } else {
          ans[i][j] = ed;
          ed++;
        }
      }
    }

    for(int i = 0; i < x; i++){
      cout << sz << " ";
      for(int j = 0; j < sz; j++){
        cout << ans[i][j] << " ";
      }
      cout << endl;
    }
  }

  else{
    cout << "No" << endl;
  }

  return 0;
}
