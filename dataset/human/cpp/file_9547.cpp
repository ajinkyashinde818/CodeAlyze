#include <iostream>
#include <string>

int main(void){
  int N, M, counter = 0;
  bool is_exist = false;
  std::string line;

  std::cin >> N >> M;
  std::cin.ignore();

  char a[N][N], b[M][M];

  for (int i = 0; i < N; i++) {
    getline(std::cin, line);
    for (int j = 0; j < N; j++) {
      a[i][j] = line[j];
    }
  }
  for (int i = 0; i < M; i++) {
    getline(std::cin, line);
    for (int j = 0; j < M; j++) {
      b[i][j] = line[j];
    }
  }

  for (int i = 0; i <= N-M; i++) {
    for (int j = 0; j <= N-M; j++) {
      counter = 0;
      for (int k = 0; k < M; k++) {
        for (int l = 0; l < M; l++) {
          if (a[i+k][j+l] == b[k][l]) {
            counter++;
            if (counter == M*M) {
              is_exist = true;
            }
          }
        }
      }
    }
  }

  if (is_exist) {
    std::cout << "Yes\n";
  }else{
    std::cout << "No\n";
  }
  return 0;
}
