#include <bits/stdc++.h>
using namespace std;

int main(){
  long long N;
  cin>>N;
  vector <long long> a(N);
  long long mina=1000000000;
  long long  minuscount=0;
  long long  zerocount=0;
  long long sum=0;
  for (long long i=0;i<N;i++){
    cin>> a[i];
    if(abs(a[i])<mina){
      mina=abs(a[i]);
    }
    if(a[i]<0){
      minuscount++;
    }
    if(a[i]==0){
      zerocount++;
    }
    sum=sum+abs(a[i]);
  }
    
  if((minuscount%2==0)||(zerocount>0)){
    cout<<setprecision(18)<<sum<<endl;
    return 0;
  }
  cout<<setprecision(18)<<sum-2*mina<<endl;
  return 0;
}
