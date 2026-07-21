#include<bits/stdc++.h>
using namespace std;

int main(){
  int R,G,B,N;
  cin >> R >> G >> B >> N;
  long long sum=0;
  for(int r=0;r*R<=N;r++){
    for(int g=0;g*G<=N;g++){
      int k=N-r*R-g*G;
      if(k%B==0 && 0<=k)sum++;
    }
  }
  cout << sum << endl;
}
