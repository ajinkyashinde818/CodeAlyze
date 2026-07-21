#include<bits/stdc++.h>
using namespace std;

int main(){
  long long N,cnt=0,sum=0,minA=1000000001;
  cin >> N;
  
  for(int i=0;i<N;i++){
    long long a;
    cin >> a;
    sum += abs(a);
    minA = min(minA,abs(a));
    if(a<0) cnt++;
  }
  
  if(cnt%2==0) cout << sum << endl;
  else cout << sum - minA*2 << endl;
  return 0;
}
