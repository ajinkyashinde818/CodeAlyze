#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int main(int argc, char *argv[]){

  int N;
  cin>>N;
  vector<int> A(N);
  int a;
  int mcount=0;
  int zerocount=0;
  for(int i=0; i<N; i++){
    cin>>a;
    A[i]=a;
    if(a<0) mcount++;
    if(a==0) zerocount++;
  }
  if(mcount%2==0 || zerocount!=0){
   
    long long sum=0;
    for(int i=0; i<N; i++){
      sum+=abs(A[i]);
    }
    cout<<sum<<endl;
    return 0;
  }
  else{
    vector<int> tmp(N);
    for(int i=0; i<N; i++){
      tmp[i]=abs(A[i]);
    }
    int min = *std::min_element(tmp.begin(), tmp.end());
    long long sum=0;
    for(int i=0; i<N; i++){
      sum+=abs(A[i]);
    }
    sum=sum-(2*min);
    cout<<sum<<endl;
  }
}
