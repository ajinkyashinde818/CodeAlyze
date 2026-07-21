#include<iostream>
using namespace std;

int main(){
  int R,G,B,N;
  int result=0;
  cin >> R >> G >> B >> N;
  for(int r=0; r<=N; r++){
    for(int g=0; g <=N; g++){
      int b = N - r*R - g*G;
      if(b < 0) break;
      if(b%B==0) result++;
  
    }
  }
  cout<<result<<endl;

  return 0;
}
