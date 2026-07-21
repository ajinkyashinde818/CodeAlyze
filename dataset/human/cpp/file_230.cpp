#include <iostream>
#include <stack>
using namespace std;
long long r,g,b,n,ans;

int main(){
	cin>>r>>g>>b>>n;
	for(int i=0;i<=3000;i++){
	    for(int j=0;j<=3000;j++){
	        if(i*r+j*g<=n && (n-i*r-j*g)%b==0)ans++;
        }
    }
    cout<<ans<<endl;
return 0;
}
