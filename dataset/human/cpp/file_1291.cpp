#include<iostream>
#include<algorithm>
#include<cstdio>
#include<queue>
#include<cstring>
#include<algorithm>
#include<stack>
#include<set>
#include<map>
#include<vector>
#include<cmath>
using namespace std;
int main(){
	long long x,y,z,n;
	cin>>x>>y>>z>>n;
	long long ans=0;
	for(int i=0;i*x<=n;i++){
		for(int j=0;i*x+j*y<=n;j++){
			if((n-i*x-j*y)%z==0) ans++;
		}
	}
	cout<<ans;
    return 0;
}
