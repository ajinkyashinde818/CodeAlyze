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
typedef unsigned int uint;
using namespace std;

int main(){
  int N,M;
  cin >> N >> M;
  string a[N];
  string b[M];
  for(int i=0;i<N;i++) cin >> a[i];
  for(int i=0;i<M;i++) cin >> b[i];

  for(int i=0;i<=N-M;i++){
    for(int j=0;j<=N-M;j++){
      bool check = true;
      for(int k=0;k<M;k++){
        for(int l=0;l<M;l++){
          if(a[i+k][j+l] != b[k][l]) check = false;
        }
      }
      if(check){
        cout << "Yes" << endl;
        return 0;
      }
    }
  }

  cout << "No" << endl;
  return 0;
}
