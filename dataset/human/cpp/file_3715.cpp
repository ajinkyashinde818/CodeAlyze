#include <iostream>
using namespace std;

int main(){
  long  sum=0,x,amin=10000000001;
  int cnt=0,N;
  cin >> N ;
  for(int i=0;i<N;i++){
    cin >> x;
    sum+=abs(x);
    if(x<=0){cnt++;}
    amin=min(amin,abs(x));
  }
  if(cnt%2==1)sum-=2*amin;
  cout << sum << endl;
  return 0;
}
