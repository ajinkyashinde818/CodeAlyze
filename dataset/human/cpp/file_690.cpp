#include<iostream>
using namespace std;
int main(){
  int n;
  int r,g,b;
  cin>>r>>g>>b>>n;
  
  int cnt=0;
  for(int i=0;i<=n;i++){
    for(int j=0;j<=n;j++){
      if(n-i*r-j*g>=0&&(n-i*r-j*g)%b==0){
	cnt++;
      }
    }
  }
  cout<<cnt<<endl;
  return(0);
}
