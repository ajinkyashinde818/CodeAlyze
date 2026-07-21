#include<bits/stdc++.h>
using namespace std;

int main(){
  int N;
  bool zero=false;
  int count=0;
  int min=1000000000;
  cin>> N;
  long sum=0;
  for(int i=0; i<N; i++){
    int a; cin >> a;
    if(a==0) zero=true;
    if(a<0) count++;
    if(min>abs(a)) min=abs(a);
    sum+=abs(a);
  }
  if(!(zero || count%2==0)) sum-=2*min;
  cout << sum << endl;
  return 0;
}
