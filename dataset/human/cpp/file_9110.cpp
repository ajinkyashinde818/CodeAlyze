#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N,M;
  cin >> N >> M;
  vector<string> A(N);
  string pattern = "";
  for(int i=0;i<N;i++){cin >> A.at(i);}
  for(int i=0;i<M;i++){
    string temp;
    cin >> temp;
    pattern += temp;
  }
  
  //パターンマッチ
  bool flag = false;
  string x;
  for(int i=0;i<N-M+1;i++){
    for(int j=0;j<N-M+1;j++){
      x = "";
       for(int k=0;k<M;k++){
	       x += A.at(i+k).substr(j,M);
       }
      if(x==pattern){
        flag = true;
        break;
      }
    }
    if(flag){
      break;
    }
  }
  
  if(flag){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
}
