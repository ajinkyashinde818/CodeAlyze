#include <bits/stdc++.h>                                                                              
using namespace std;                                                                                  
using ll = long long;                                                                                 
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }               
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }               
                                                                                                      
int main() {                                                                                          
  int n;                                                                                              
  int r;                                                                                              
  cin >> n >> r;                                                                                      
  if (n < 10) {                                                                                       
    cout << r + 100 * (10 - n) << endl;                                                               
  } else {                                                                                            
    cout << r << endl;                                                                                
  }                                                                                                   
  return 0;                                                                                           
}
