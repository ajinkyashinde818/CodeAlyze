#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <list>
#include <cmath>
#include <stack>
#include <string>
#include <cstring>
#include <numeric>
#include <iomanip>
#include <fstream>
using namespace std;
long long mod=1e9+7;
int main(){
	int n;
	string s;
	cin>>n>>s;
	vector<int> c[26];
	for(int i=0;i<n;i++){
		c[s[i]-'a'].push_back(i);
	}
	long long ans=1;
	for(int i=0;i<26;i++){
		(ans*=(1+c[i].size()))%=mod;
	}
  	(ans+=mod-1)%=mod;
	cout<<ans<<endl;
	return 0;
}
