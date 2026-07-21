#include <iostream>
using namespace std;
int main(void){
  int n, m;
  bool flag=false;
  string a[55];
  string b[55];
  cin >> n >> m;
  for(int i=0; i<n; i++){
    cin >> a[i];
  }
  for(int j=0; j<m; j++){
    cin >> b[j];
  }

  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      if(b[0][0]==a[i][j]){flag=true;}
        for(int k=0; k<m && flag; k++){
          for(int l=0; l<m && flag; l++){
            if(b[k][l]!=a[i+k][j+l]){flag=false;}
            if(k==m-1 && l==m-1){cout << "Yes" << endl;return 0;}
          }
        }

    }
  }
  cout << "No" << endl;
  return 0;

}
