#include <bits/stdc++.h>
using namespace std;
long long N,A,counter=0,sum=0,mini=1000000000+10;
int main(){
  cin >> N;
  for(int i=0;i<N;i++){
    cin >> A;
    if(A<0) counter++;
    sum+=abs(A);
    if(mini>abs(A)) mini=abs(A);
  }
  if(counter%2==0) cout << sum << endl;
  else cout << sum-2*mini << endl;
  return 0;
}
