#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
  long long n;
  cin>>n;
  vector<long long> vec(n);
  long long minusnum=0;
  long long exit0=0;
  for(long long i=0; i<n; i++){
    cin>>vec[i];
    if(vec[i]<0){
      minusnum++;
      vec[i]=vec[i]*(-1);
    }else if(vec[i]==0){
      exit0=1;
    }
  }
  sort(vec.begin(),vec.end());
  long long sum=0;
  if(exit0==1||minusnum%2==0){
    for(long long i=0; i<vec.size(); i++){
      sum+=vec[i];
    }
  }else{
    sum -= vec[0];
    for(long long i=1; i<vec.size(); i++){
      sum+=vec[i];
    }
  }
  cout<<sum<<endl;
  return 0;
}
