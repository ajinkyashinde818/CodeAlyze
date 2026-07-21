#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<climits>
using namespace std;
int main(){
  int n;
  int minus=0;
  int minimum=INT_MAX;
  long long sum=0;

  cin>>n;
  for(int i=0;i<n;i++){
    int data;
    cin>>data;
    sum+=abs(data);
    if(data<0){
      minus++;
    }
    minimum=min(minimum,abs(data));
  }

  if(minus%2==0){
    cout<<sum<<endl;
  }else{
    cout<<sum-minimum*2<<endl;
  }
  return(0);
}
