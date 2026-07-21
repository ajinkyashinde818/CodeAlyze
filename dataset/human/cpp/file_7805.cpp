#include <bits/stdc++.h>
using namespace std;
 
int main() {
  long long N,sum,b,min;
  sum=0; b=0;
  cin >> N;
  vector<long long> a(200009);
  for(long long i=0;i<N;i++){cin >> a[i];}
  for(long long i=0;i<N;i++){sum+=a[i];}
  min=100000000;
  if(N==2){min=abs(a[0]-a[1]);}
  else{
    for(long long i=0;i<N-2;i++){
      b+=a[i];
      if(min>abs(sum-2*b)){min=abs(sum-2*b);}
    }
  }
  cout << min << endl;
}
