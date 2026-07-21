#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int R,G,B,N;cin>>R>>G>>B>>N;
  int M=0;
  for(int r=0;r<=5000;r++){
    for(int g=0;g<=5000;g++){
      if((N-(R*r+G*g))%B==0&&(N-(R*r+G*g))>=0)M++;
    }
  }
  cout<<M<<endl;
}
