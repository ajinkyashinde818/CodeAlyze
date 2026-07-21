#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>
#include<cstring> 
#include<cassert>
#include<cmath>
#include<sstream>
#include<fstream>
#include<map>
#include<set>
#include<vector>
#include<queue>
#include<stack>
#include<bitset>
using namespace std;
long long a[100005];
int main(){
	int n;
	cin>>n;
	long long mi=2e9,cnt=0;
	long long sum=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
	//	cout<<a[i]<<endl;
		mi=min(mi,abs(a[i]));
		if(a[i]<0) cnt++;
		sum+=abs(a[i]);
	}
//	cout<<cnt<<endl;
	if(cnt%2){
		cout<<sum-2*mi;
	}
	else cout<<sum;
	
}
