#include<iostream>
#include<iomanip>
#include<algorithm>
#include<cstring>
#include<string>
#include<cmath>
#include<vector>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
using namespace std;
const int inf=2147483647,dx[]={-1,0,1,0},dy[]={0,-1,0,1};// 上 左 下 右
const int N=100005,M=1000005,mod=1000000007;
const long long llinf=9223372036854775807ll;
int r,g,b,n,ans;
int main(){
	cin>>r>>g>>b>>n;
	for(int i=0;i<=n/r;i++)
		for(int j=0;j<=n/g;j++)
		{
			int num=n-i*r-j*g;
			if(num/b<0)
				continue;
			if(num%b==0)
				ans++;
		}
	cout<<ans;
	return 0;
}
