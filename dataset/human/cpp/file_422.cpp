#include <iostream>

int main() {
  int R,G,B,N;
  std::cin >> R >> G >> B >> N;
  int cnt=0;
  for(int r=0;r<=N/R;r++){
    for (int g=0;g<=N/G;g++){
      int bB = N - r*R - g*G;
      if (bB >=0 && bB%B==0)
        cnt++;
    }
  }
  std::cout << cnt << std::endl;
  return 0;
}
