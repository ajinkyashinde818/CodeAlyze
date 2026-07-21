#include <iostream>

bool check[200005]={0};
int seq[300005];
int a[100005];

int main(){

  int n, m;

  std::cin >> n >> m;
  for(int i = 1; i <= m; i++) std::cin >> a[i];

  for(int i = 0; i <= m; i++){
    seq[i] = a[m - i];
  }

  for(int i = 0; i < m; i++){
    if(check[seq[i]] == 0){
      std::cout << seq[i] << std::endl;
      check[seq[i]] = true;
    }
  }
  for(int i = 1; i <= n; i++){
    if(check[i] == 0){
      std::cout << i << std::endl;
      check[i] = true;
    }
  }

  return 0;
}
