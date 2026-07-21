#include <iostream>
#include <algorithm>
using namespace std;

int main(){
  int n;
  int i,j=0,k;
  cin >> n;
  long long a[n],ret=0,m=1000000010;
  for(i=0;i<n;i++){
    cin >> a[i];
    ret+=abs(a[i]);
    if(a[i]<0)j++;
    m=min(m,abs(a[i]));
  }
  if(j%2==1){
    ret-=2*m;
    //cout << ret << " " << m << endl;
  }
  cout << ret << endl;
  return 0;
}
