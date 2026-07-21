#include<iostream>
#include<algorithm>
#include<string>
#include<cstdlib>
#include<map>
#include<iomanip>
#include<sstream>
#include<vector>
#include<stack>
#include<math.h>
#include<queue>
#include<complex>
using namespace std;

const long long int mod=1000000007;
const long long int INF=99999999999999999;
long long int kaizyou[200005],kaizyouex[200005];
long long int n,k,res=1,coub=0,couw=0,y,m,d,a[20005],ooki[2005]={};
long long int dp[200005]={};
queue<pair<long long int,long long int> >que;
string str,strtmp="f";


//累乗(繰り返し2乗法)　aのb乗(mod)を求める。
long long int rui(long long int a, long long int b, long long mod) {
	int memo[65] = {};
	long long int A[65] = {};
	long long int tmp = 1;
	for (int i = 0; i < 65; i++) {
		memo[i] = b % 2;
		b /= 2;
	}

	A[0] = a;
	A[0] %= mod;

	for (int i = 1; i < 65; i++) {
		A[i] = A[i - 1] * A[i - 1];
		A[i] %= mod;
	}
	for (int i = 0; i < 65; i++) {
		if (memo[i] == 1) {
			tmp *= A[i];
			tmp %= mod;
		}
	}
	tmp %= mod;
	return tmp;
}


int main() {
	cout << fixed << setprecision(10);
	cin>>n>>str;
	kaizyou[0]=1;
	for(int i=1;i<=2*n;i++){
		res*=i;
		res%=mod;
		kaizyou[i]=res;
		//cout<<kaizyou[i]<<endl;
	}
	m=1;
	kaizyouex[0]=1;
	for(int i=1;i<=2*n;i++){
		m*=kaizyou[i];
		m%=mod;
		kaizyouex[i]=m;
		//cout<<kaizyouex[i]<<endl;
	}
	long long int now=0;
	bool key=true;
	for(int i=0;i<2*n;i++){
		if(now%2==0&&key&&str[i]=='B'){
			now++;
			key=true;
		}else if(now%2==0&&!key&&str[i]=='B'){
			now--;
			key=false;
		}else if(now%2==0&&key&&str[i]=='W'){
			now=now;
			key=false;
		}else if(now%2==0&&!key&&str[i]=='W'){
			now=now;
			key=true;
		}else if(now%2==1&&key&&str[i]=='B'){
			now=now;
			key=false;
		}else if(now%2==1&&!key&&str[i]=='B'){
			now=now;
			key=true;
		}else if(now%2==1&&key&&str[i]=='W'){
			now++;
			key=true;
		}else if(now%2==1&&!key&&str[i]=='W'){
			now--;
			key=false;
		}
		if(now<=0||now>n){
			cout<<0<<endl;
			return 0;
		}
		if(key==true){
			strtmp.push_back('s');
		}else{
			strtmp.push_back('f');
		}
	}
	
	if(now!=1){
		cout<<0<<endl;
		return 0;
	}
	res=kaizyou[n];
	
	long long int nows=0,nowf=0;
	for(int i=2*n;i>=0;i--){
		if(strtmp[i]=='f'){
			nowf++;
		}else{
			res*=nowf;
			res%=mod;
			//res*=kaizyou[nows];
			
			nowf--;
			//cout<<res<<endl;
		}
		//cout<<nows<<" "<<nowf<<endl;
	}

	cout<<res<<endl;
}
