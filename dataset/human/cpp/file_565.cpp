#include <iostream>                                                                              
using namespace std;                                                                             
                                                                                                 
int main() {                                                                                     
  int r, g, b, n;                                                                                
  int c = 0;                                                                                     
                                                                                                 
  cin >> r >> g >> b >> n;                                                                       
                                                                                                 
  for (int i = 0;i*r <= n;i++) {                                                                 
    int diff = n - r * i;                                                                        
    for (int j = 0;i*r + j*g <= n; j++) {                                                        
      if ((n - (r * i + g * j))%b == 0) {                                                        
        c++;                                                                                     
      }                                                                                          
    }                                                                                            
  }                                                                                              
  cout << c;                                                                                     
  return 0;                                                                                      
}
