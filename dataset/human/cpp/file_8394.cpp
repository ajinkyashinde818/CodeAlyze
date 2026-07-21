#include<iostream> 
#include<vector>
using namespace std;
int main(){
  int n=0,m=0;
  bool check = true,ans = false;
  cin >> n >> m;
  char a[n][n],b[m][m];
  for(int i=0;i<n;i++) for(int j=0;j<n;j++) cin >> a[i][j];
  for(int i=0;i<m;i++) for(int j=0;j<m;j++) cin >> b[i][j];
  for(int i=0;i<n;++i){
    for(int j=0;j<n;++j){
      if(i+m-1>=n || j+m-1>=n) continue;
      //画像の照合
      check = true;
      for(int k = 0;k<m;k++){
        for(int l = 0;l<m;l++){
          if(a[k+i][l+j] != b[k][l]){ check = false;}
        }
      }
      if(check) ans = true;
     }
  }
  if(ans) cout << "Yes" << endl;
  else cout << "No" << endl;
}
