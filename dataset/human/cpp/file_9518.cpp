#include <iostream>
#include <vector>
#include <bitset>
#include <string>
using namespace std;

using bits = bitset<5001>;

int main(){
  int n,m;
  cin >> n >> m;

  vector<string> a(n),b(m);
  for(int i=0; i<n; i++) cin >> a[i];
  for(int i=0; i<m; i++) cin >> b[i];

  int d = n*2;

  bits x,y,mask;
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      x.set( i*d + j , a[i][j] != '.' );
    }
  }

  for(int i=0; i<m; i++){
    for(int j=0; j<m; j++){
      y.set( i*d + j , b[i][j] == '.');
      mask.set(i*d + j, 1);
    }
  }

  for(int i=0; i+m<=n; i++){
    for(int j=0; j+m<=n; j++){
      int cnt = ((x ^ (y<<(i*d + j))) & (mask<<(i*d+j)) ).count();
      if(cnt == m*m){
        cout << "Yes" << endl;
        return 0;
      }
    }
  }
  cout << "No" << endl;


  return 0;
}
