#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<string>
#include<random>
#include<map>
#include<queue>
using namespace std;


int main(){

  int n, m;
  cin >> n >> m;

  vector<string> a(n);
  vector<string> b(m);
  for(int i=0; i<n; i++) cin >> a[i];
  for(int i=0; i<m; i++) cin >> b[i];

  for(int ai=0; ai<n; ai++){
    for(int aj=0; aj<n; aj++){

      if( ai + m > n ) continue;
      bool f = true;
      for(int bi=0; bi<m; bi++){
        for(int bj=0; bj<m; bj++){
          if( a[ai+bi][aj+bj] != b[bi][bj] ){
            f = false;
            break;
          }
        }
        if( !f ) break;
      }
      if( f ){
        cout << "Yes" << endl;
        return 0;
      }

    }
  }

  cout << "No" << endl;

  return 0;
}








// EOF
