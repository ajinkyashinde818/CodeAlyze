#include<bits/stdc++.h>
using namespace std;

int main(){

  int N, i;
  cin>>N;
  vector<int> a(N);
  long long Sums=0, Suma=0, mn=10000000000000000;
  for(i=0; i<N; i++){
    cin>>a[i];
    Sums+=a[i];
  }
  
  for(i=0; i<N-1; i++){
    Suma+=a[i];
    Sums-=a[i];
    mn=min(mn, abs(Sums-Suma));
  }
  
  cout<<mn<<endl;
  return 0;
}
