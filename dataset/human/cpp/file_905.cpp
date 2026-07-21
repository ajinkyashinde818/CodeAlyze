#include <iostream>
#include <string>
using namespace std;

int main() {
  int R,G,B,N;
  cin>>R>>G>>B>>N;
  int count=0;
  for(int r=0;r*R<=N;r++){
    for(int g=0;g*G<=N-r*R;g++){
      if((N-r*R-g*G)%B==0)count++;
    }
  }
  cout<<count<<endl;
  return 0;
}
