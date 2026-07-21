#include <iostream> 
#include <string> 
#include <vector> 
#include <cmath> 
#include <algorithm> 
#include <cstdlib> 
#include <ctime> 
#include <cstdio> 
#include <functional> 
#include <set> 
#include <sstream> 
#include <cctype>
#include <stack>
#include <queue>
#include <cstring>
#include <map>
#include <list>
#include <cassert>
 
using namespace std; 

long long dp[51][51][3000]={};

int main(){

	int n,m;
	cin>>n>>m;

	vector<string> A(n),B(m);
	for(int i=0;i<n;i++) cin>>A[i];
	for(int i=0;i<m;i++) cin>>B[i];

	for(int i=0;i<=n-m;i++){
		for(int j=0;j<=n-m;j++){

			bool ok=true;

			for(int k=0;k<m && ok;k++){
				for(int l=0;l<m && ok;l++){
					if(A[i+k][j+l]!=B[k][l]) ok=false;
				}
			}

			if(ok){
				cout<<"Yes"<<endl;
				return 0;
			}

		}
	}

	cout<<"No"<<endl;
	return 0;

}
