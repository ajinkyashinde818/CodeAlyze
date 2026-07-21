#include <iostream>                                   
#include <cmath>                                      
using namespace std;                                  
                                                      
int main(void){                                       
  int n;                                              
  long int ans = 0,max = 0,minnum =1000000000;        
  int sign = 0;                                       
  cin >> n;                                           
  int a[n];                                           
                                                      
  for(int i = 0; i < n;++i){                          
    cin >> a[i];                                      
    if(a[i] < 0) sign++;                              
    if(minnum > abs(a[i])) minnum = abs(a[i]);        
    max += abs(a[i]);                                 
  }                                                   
  //偶数                                                
  if(sign % 2 == 0) cout << max << endl;              
  else cout << max-2*minnum << endl;                  
  return 0;                                           
}
