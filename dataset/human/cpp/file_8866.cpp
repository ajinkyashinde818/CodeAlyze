#include <bits/stdc++.h>
using namespace std;

string a[51], b[51];
int n, m;

int main()
{
	cin>>n>>m;
	for(int i=0; i<n; ++i) cin>>a[i];
	for(int i=0; i<m; ++i) cin>>b[i];
	
	for(int i=0; i<=n-m; ++i){
		for(int j=0; j<=n-m; ++j){
			auto f = [&](){
				for(int k=0; k<m; ++k){
					if(a[i+k].substr(j, m) != b[k]) return false;
				}
				return true;
			};
			if(f()){
				puts("Yes");
				return 0;
			}
		}
	}
	puts("No");
	return 0;
}
