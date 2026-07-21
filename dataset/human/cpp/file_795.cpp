#include <iostream>
using namespace std;

int main() {
	int r,g,b,k;
	int ans=0;
	cin>>r>>g>>b>>k;
	for(int i=0;i<3001;i++){
		for(int j=0;j<3001;j++){
			if((k-r*i-g*j)>=0 &&(k-r*i-g*j)%b==0)
			ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}
