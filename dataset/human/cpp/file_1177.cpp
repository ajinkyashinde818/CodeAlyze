#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main() {
  int R, G, B, N, A = 0;
  std::cin >> R >> G >> B >> N;


  for (int r = 0; r <= N; r+=R) {
    for (int rg = r; rg <= N ; rg+=G) {
      
        if ((N-rg)%B==0 ) {
          A += 1;
        }
      
    }
  }

  std::cout << A << std::endl;
  return 0;
}
