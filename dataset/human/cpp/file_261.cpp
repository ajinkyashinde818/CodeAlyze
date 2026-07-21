#include <bits/stdc++.h>
using namespace std;
 
int main() {	//N個の整数から連続するK個を選ぶ
  int R, G, B, N, count = 0;
  
  cin >> R >> G >> B >> N;

  for (int i=0; i<N+1; i++){
    
    if (i*R > N)
      break;
    
    for (int j=0; j<N+1; j++){
            
      if (i*R + j*G > N)
        break;
      
      if ( (N-i*R-j*G) % B == 0)
        count++;

    }
    
  }
  
  cout << count << endl;
  
}
