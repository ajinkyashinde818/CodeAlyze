#include <iostream>
#include <vector>
#include <array>
#include <set>
#include <cmath>
#include <string>
#include <queue>
#include <list>
#include <unordered_map>
#include <algorithm>
#include <functional>
#include <iomanip> // std::std::setprecision(X)
#include <limits>  //std::numeric_limits<int>::max(), min()

int main (void) {

  int N, M; std::cin >> N >> M;
  std::vector<std::vector<char>> A(N, std::vector<char>(N));
  std::vector<std::vector<char>> B(M, std::vector<char>(M));

  for(int i=0; i<N; i++) for(int j=0; j<N; j++) std::cin >> A[i][j];
  for(int i=0; i<M; i++) for(int j=0; j<M; j++) std::cin >> B[i][j];

  if( N == M ) {
    for(int i=0; i<N; i++) {
      for(int j=0; j<M; j++) {
        if ( A[i][j] != B[i][j] ) {
          std::cout << "No" << std::endl;
          return 0;
        }
      }
    }
    std::cout << "Yes" <<std::endl;
    return 0;
  }
  for(int i=0; i<N-M; i++) {
    for(int j=0; j<N-M; j++) {

      bool check = true;
      for(int k=0; k<M; k++) {
        for(int l=0; l<M; l++) {
          if ( B[k][l] != A[i+k][j+l] ) check = false;
          if(false) break;
        }
        if(false) break;
      }
      if(check){
        std::cout << "Yes" << std::endl;
        return 0;
      }
    }
  }
  std::cout << "No" << std::endl;

  return 0;
}
