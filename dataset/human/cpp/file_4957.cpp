#include<iostream>
#include<string>
#include<algorithm>
#include<math.h>
#include<vector>
#include<utility>
#include<queue>
#include <map>

using namespace std;

int main(){

	int n,k;
	cin>>n>>k;
	int ans=0;
	if(n>=10)ans=k;
	else ans=k+100*(10-n);


	cout<<ans;
	cout<<endl;

	return 0;
}
