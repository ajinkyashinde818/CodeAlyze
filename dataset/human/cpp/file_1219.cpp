#include <iostream>
using namespace std;

int main() {
	int r,g,b,n;
	cin>>r>>g>>b>>n;
	long long p=0;
	int i=0,j=0,a,c;
	for(int i=0;i<=n;i+=r)
	{
		for(int j=0;j<=n;j+=g)
		{
			if ( (n-i-j)%b ==0 && (n-i-j)>=0)
			p++;
		}
		
	}
	cout<<p;
	// your code goes here
	return 0;
}
