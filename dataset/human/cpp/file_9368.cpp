#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,M;
  cin >> N>>M;
  vector<string> Ns(N);
  vector<string> Ms(M);
  for(int i = 0; i < N;i++){
    cin >> Ns.at(i);
  }
  for(int i = 0; i < M;i++){
    cin >> Ms.at(i);
  }
  
  for(int y = 0; y <= N-M;y++){
    for(int x = 0; x <= N-M;x++){
      //左上を決める
      bool ret = true;
      for(int Y = 0; Y < M;Y++){
	    for(int X = 0; X < M;X++){
			if(Ms.at(Y).at(X)!= Ns.at(y+Y).at(x+X)){
          	   ret = false;
         	   break;
         	}      
  		}
      }
      if(ret) {cout <<"Yes" ; return 0;}
  	}
  }
  
  cout << "No" ;
  return 0;
}
