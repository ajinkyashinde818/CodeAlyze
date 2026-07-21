#include<iostream>
using namespace std;

int r,g,b,n,ans=0,i,j;

int main(){
  cin>>r>>g>>b>>n;
  for (i=0;i*r<=n;i++){
  	for (j=0;j*g<=n-i*r;j++){
  		if ((n-i*r-j*g)%b==0)
  			ans++;
    	}
  }
  cout<<ans;
  
  return 0;
}
