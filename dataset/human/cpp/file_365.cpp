#include<bits/stdc++.h>
using namespace std;

int main(){
  int M, N, K, n;
  int t = 0;
  cin >> M >> N >> K >> n;
/*
  vector<char> S(N);
  for(int i = 0; i < N; i++)
    cin >> S.at(i);
*/
  for(int i = 0; M*i <= n; i++){
    for(int j = 0; N*j <= n; j++){
      int k = 0;
      while(M*i+N*j+K*k<n){
        k++;
      }
      if(M*i+N*j+K*k==n) t++;
    }
  }
  
  cout << t << endl;
}
