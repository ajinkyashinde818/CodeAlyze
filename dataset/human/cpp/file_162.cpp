#include <iostream>

using namespace std;

int main()
{
  int R, G, B, N;
  cin >> R >> G >> B >> N;
  
  int count = 0;
  for(int i = 0; i <= N/R; i++) {
      for(int j = 0; j <= N/G; j++) {
          int k = (N - i*R - j*G) / B;
          if(k < 0)
              break;
          if(i*R + j*G + k*B == N)
              count++;
      }
  }
  
  cout << count << endl;
}
