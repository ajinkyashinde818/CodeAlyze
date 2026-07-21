#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
  int R,G,B,N;
  std::cin >> R>>G>>B>>N;
  int rm = N/R;
  int gm = N/G;
  int bm = N/B;
  int cnt=0;
  for(int i=0;i<=rm;i++){
    for(int j=0;j<=(N-i*R)/G;j++){
      if((N-i*R-j*G)%B==0){
        cnt++;
      }
    }
  }

  std::cout << cnt << '\n';
}
