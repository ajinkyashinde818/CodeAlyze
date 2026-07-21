#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <cstdlib>
#include <cmath>

using namespace std;

int main(){
  int N,M;
  cin >> N >> M;
  vector<string> A(N);
  vector<string> B(M);
  for(int i=0;i<N;i++){
    cin >> A.at(i);
  }
  for(int i=0;i<M;i++){
    cin >> B.at(i);
  }

  for(int i=0;i<N-M+1;i++){
    for(int j=0;j<N-M+1;j++){
      bool flag=true;
      for(int k=0;k<M;k++){
        for(int l=0;l<M;l++){
          if(B.at(k).at(l)!=A.at(i+k).at(l+j))  flag=false;
        }
      }
      if(flag){
        cout << "Yes" << endl;
        return 0;
      }
    }
  }

  cout << "No" << endl;

  return 0;
}
