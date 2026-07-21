#include<bits/stdc++.h>
using namespace std;
int main(){
	int r,g,b,n;cin>>r>>g>>b>>n;
  long long num_ways=0;
  for(int i=0 ; i*r<=n;i++)
    for(int j=0;j*g<=n;j++){
    	if(n<(i*r+j*g))continue;
      else{
      	if((n-i*r-j*g)%b==0)num_ways++;
      }
    }
  cout<<num_ways;
}
