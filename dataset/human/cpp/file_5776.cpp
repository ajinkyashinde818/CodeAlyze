#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <cmath>
#include <bitset>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	long long int l;
	scanf("%d %lld", &n, &l);
	vector<string> s;
	for(int i=0; i<n; i++){
		string s1;
		cin >> s1;
		s.push_back(s1);
	}
	sort(s.begin(), s.end());
	vector<long long int> v;
	for(int k=0; k<=n; k++){
		if(k==0){
			for(long long int i=0; i<(long long int)s[0].length(); i++){
				if(s[0][i]=='1') v.push_back(l-i);
			}
		}else if(k==n){
			for(long long int i=0; i<(long long int)s[n-1].length(); i++){
				if(s[n-1][i]=='0') v.push_back(l-i);
			}
		}else{
			long long int i0;
			for(long long int i=0; i<(long long int)s[k].length(); i++){
				if(s[k][i]!=s[k-1][i]){
					i0=i;
					break;
				}
			}
			for(long long int i=i0+1; i<(long long int)s[k].length(); i++){
				if(s[k][i]=='1') v.push_back(l-i);
			}
			for(long long int i=i0+1; i<(long long int)s[k-1].length(); i++){
				if(s[k-1][i]=='0') v.push_back(l-i);
			}
		}
	}
	if(v.empty()){
		printf("%s\n", "Bob");
		return 0;
	}
	long long int ans=0;
	for(int i=0; i<v.size(); i++){
		long long int a=1;
		while(v[i]%2==0){
          v[i]/=2;
          a*=2;
        }
		ans^=a;
	}
	if(ans==0){
		printf("%s\n", "Bob");
	}else{
		printf("%s\n", "Alice");
	}
	return 0;
}
