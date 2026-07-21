#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main(){
  int n, m;
  std::cin >> n >> m;
  vector<string> a(n), b(m);
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  for (int i = 0; i < m; i++) {
    std::cin >> b[i];
  }
  for (int i = 0; i < n - m + 1; i++) {
    for (int j = 0; j < n - m + 1; j++) {
      for (int y = i; y < i + m; y++) {
        for (int x = j; x < j + m; x++) {
          if(a[y][x] != b[y - i][x - j])x = y = 1e9;
        }
        if(y == i + m - 1){
          std::cout << "Yes" << std::endl;
          return 0;
        }
      }
    }
  }
  std::cout << "No" << std::endl;
  return 0;
}
