#include<iostream>
#include<vector>
using namespace std;
int abs(int a){
  if(a<0) return a*(-1);
  else return a;
}
int main(){
  int n,i,a,count=0,absmin;
  long sum;
  cin>>n;
  cin>>a;
  absmin=abs(a);
  sum=absmin;
  if(a<0) count++;


  for(i=1;i<n;i++){
    cin>>a;
    sum+=abs(a);
    if(abs(a)<absmin) absmin=abs(a);
    if(a<0) count++;
  }

  if(count%2) sum-=(absmin*2);

  cout<<sum<<endl;
  return 0;
}
