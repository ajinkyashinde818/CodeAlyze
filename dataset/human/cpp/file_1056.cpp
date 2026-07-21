#include <bits/stdc++.h>
using namespace std;
int main() {
  int R, G, B, N;
  int result = 0;
  cin>>R>>G>>B>>N;
  for(int r=0; r<=N; r++) {
    for(int g=0; g<=N; g++) {
      int tmp = N - R*r - G*g;
      if(tmp >= 0 && tmp % B == 0) {
        result++;
      }
    }
  }
  cout<<result<<endl;
}
