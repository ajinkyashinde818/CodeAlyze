#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

int main(){
  int n,m;
  cin >> n >> m;
  string a[n];
  string b[m];
  for(int i = 0; i< n; i++){
    string tempa;
    cin >> tempa;
    a[i] = tempa;
  }
  for(int i = 0; i< m; i++){
    string tempb;
    cin >> tempb;
    b[i] = tempb;
  }

  bool result = false;

  //以下全探索
  for(int upleft = 0; upleft<=n-m; upleft++){
    for(int upright = 0; upright <= n-m; upright++){
      bool check = true;
      for(int k = 0; k<m; k++){
        for(int s = 0; s<m; s++){
          if(a[upleft+k][upright+s] != b[k][s]){
            check = false;
            break;
          }
        }
      }
      if(check){
        result = true;
        break;
      }
    }
  }

  if(result){
    cout << "Yes" << endl;
  }
  else{
    cout << "No" << endl;
  }
}
