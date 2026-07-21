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
int main(){
	int r,g,b,n;
	cin>>r>>g>>b>>n;
	int cnt=0;
	for(int i=0;i*r<=n;i++){
		for(int j=0;i*r+j*g<=n;j++){
			int re=n-i*r-j*g;
			if(re%b==0) cnt++;
		}
	}
	cout<<cnt;
}
