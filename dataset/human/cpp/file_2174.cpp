#include <bits/stdc++.h>
using namespace std;

int main() {
  
  long long N;
  cin >> N;
  
  vector<long long> As(N);
  for(int i=0; i<N; i++){ cin >> As.at(i); }
  
  long long res=0;
  long long minn=abs(As.at(0));
  long long mainasu=0;
  
  if(As.at(0)>0){ mainasu=0; }
  else{ mainasu++; }
  
  for(long long i=1; i<N; i++){
    minn = min( minn, abs(As.at(i)) );
    if(As.at(i)<0){ mainasu++; }
  }
  for(long long i=0; i<N; i++){ res+=abs(As.at(i)); }
  if(mainasu%2==1){ res-=2*minn; }
  
  cout << res << endl;

}
