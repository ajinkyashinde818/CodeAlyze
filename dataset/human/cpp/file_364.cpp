#include <bits/stdc++.h>
using namespace std;

int main(){
int P,Q,R,N;
  cin >> P>> Q>>R>>N;
  int count=0;
  int x = N/P+1;
  for(int i =0;i<x;i++){
    for(int j =0;j<(N-P*i)/Q+1 && i+j<N+1; j++){
      int B = N-P*i-Q*j;
      if(B%R ==0 &&B>=0)
      count ++;
        
  
      
      }
    }
  cout << count << endl;
}
