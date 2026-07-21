#include <iostream>
#include <string>
#include <cstdio>

int n, m;

char a[51][51], b[51][51];

int main(){

  std::cin >> n >> m;
  for(int i = 0; i < n; i++)
    scanf("%s", a[i]);
  for(int i = 0; i < m ; i++)
    scanf("%s", b[i]);

  int res = 0;
  bool can = false;

  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){

      if(i + m > n || j + m > n) continue;
      res = 0;
      for(int k = 0; k < m; k++){

        for(int l = 0; l < m; l++){
          if(a[i + k][j + l] == b[k][l])
          ++res;
        }
      }
      if(res == m*m){
        can = true;
        break;
      }
    }
  }

  if(can) std::cout << "Yes\n";
  else std::cout << "No\n";

}
