#include<iostream>
using namespace std;

int main(){
  int r,g,b,n;
  int cnt=0;

  cin>>r>>g>>b>>n;

  for(int i=0;i*r<=n;i++){
    for(int j=0;j*g<=n;j++){
      if(i*r+j*g>n){
        break;
      }else if((n-(i*r+j*g))%b==0){
        cnt++;
      }

    }
  }

  cout<<cnt<<endl;

  return 0;
}
