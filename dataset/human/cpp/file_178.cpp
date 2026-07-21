#include <bits/stdc++.h>
using namespace std;

int main(){
  int R,G,B,N;
  cin>>R>>G>>B>>N;
  int i=0;
  for(int r=0;r*R<=N;r++){
    int N2=N-r*R;
    for(int g=0;g*G<=N2;g++){
      if((N2-g*G)%B!=0)
        continue;
      i++;
    }
  }
  cout<<i<<endl;
}
