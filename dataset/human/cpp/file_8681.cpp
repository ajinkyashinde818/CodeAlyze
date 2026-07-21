#include <iostream>
using namespace std;
char a[105][105],b[105][105];
int main (){
  int n,m;
  cin >> n >> m;
  
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        cin >> a[i][j];
  
    for (int i = 0; i < m; i++)
      for (int j = 0; j < m; j++)
      cin >> b[i][j];
      
      for (int i = 0; i < n - m + 1; i++){
            for (int j = 0; j < n - m + 1; j++){
                  bool ans = true;
                  for (int k = 0; k < m; k++){
                      for (int y = 0; y < m; y++)
                         if (b[k][y] != a[k + i][y + j]) {ans = false; break;}
                  }
                if (ans == true) {cout<<"Yes"<<endl; return 0;}
            }
      }
    cout<<"No"<<endl;;
}
