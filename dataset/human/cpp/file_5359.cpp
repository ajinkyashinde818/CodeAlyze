#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	long long int n,dr,ir;
	cin>>n>>dr;
	long long int ans = dr + (100*(10-n));
	if(n>=10)
		cout<<dr<<endl;
	else{
		cout<<ans<<endl;
	}
	return 0;
}
