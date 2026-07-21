#include <bits/stdc++.h>
using namespace std;

int main() {
  int n , m;
  cin >> n >> m;
  if ( m > n){
    cout << "No" << endl;
    return 0;
  }
  vector <string> a(n),b(m);
  for ( int i=0 ; i< n ; i++){
    cin >> a.at(i);
  }
  for ( int i=0 ; i< m ; i++){
    cin >> b.at(i);
  }
  
  for ( int i= 0 ; i <= n-m ; i++){
    for ( int j=0 ; j<= n-m ; j++ ){
      bool ans = true ;
      for ( int k=0 ; k<=m-1 ; k++){
        for (int l=0 ; l<=m-1 ; l++){
         if ( b.at(k).at(l) != a.at(i+k).at(j+l)){
           ans = false ;
           break ;
         }
        }
        if(!ans){
          break ;
        } 
        }
      if (ans){
          cout << "Yes" << endl;
          return 0 ;
      }
    }
  }
    cout <<  "No" << endl;
}
