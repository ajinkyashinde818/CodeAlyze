#include<iostream>
using namespace std;

int main(void){
  int n,r;
  cin>>n>>r;
  int internal_rate=0;
  
  if(n<10){
    internal_rate=r+100*(10-n);
  }else{
    internal_rate=r;
  }
  
  cout<<internal_rate<<endl;
  
  return 0;
}
