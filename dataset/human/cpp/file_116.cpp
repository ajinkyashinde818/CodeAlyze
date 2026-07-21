#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main(){
  int R, G, B, N;
  cin >> R >> G >> B >> N;
  int cnt=0;
  for(int i=0; i<=N/R; i++){
    for(int j=0; j<=N/G; j++){
      int dif=N-R*i-G*j;
      if(dif%B==0 && dif>=0) cnt++; 
    }
  }
  cout << cnt << endl;
}
