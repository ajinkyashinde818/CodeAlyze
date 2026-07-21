#include <bits/stdc++.h>
 
using namespace std;
int main(){
  int N;
  cin >>N;
  vector<long long> A(N);
  long long  minnum=0;
  long long S=0;
  long long minn=LLONG_MAX;
  for(int i=0;i<N;i++){
    cin >>A.at(i);
    if(A.at(i)<0){minnum++;}
    A.at(i)=abs(A.at(i));
    S+=A.at(i);
    minn=min(minn,A.at(i));
  }
  
  if(minnum%2==0){cout <<S<<endl;}
  else{S=S-2*minn;
    cout <<S<<endl;}
}
