#include <bits/stdc++.h>
using namespace std;

int main(){
  int N1,N2,N3,Ntot;
  cin >> N1 >> N2 >> N3 >> Ntot;

  int ans= 0;
  for(int n1=0; n1<= Ntot/N1; n1++){
    for(int n2=0; n2<= Ntot/N2; n2++){
      int remain= Ntot- (N1*n1+ N2*n2);
      if(remain < 0){ break; }
      else{
        if(remain % N3==0){ ans++; }
      }
    }
  }

  cout << ans << endl;
}
