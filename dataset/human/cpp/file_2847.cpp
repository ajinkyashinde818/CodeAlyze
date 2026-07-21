#include<bits/stdc++.h>
using namespace std;
int main(){
  int N;cin>>N;int G=0;long long K=0;vector<long long>H(N);
  for(int X=0;X<N;X++){
    long long J=0;cin>>J;H[X]=abs(J);K+=abs(H[X]);
    if(J>=0)G++;
  }
  sort(H.begin(),H.end());
  if(G%2==N%2)cout<<K<<endl;
  else cout<<K-H[0]*2<<endl;
}
