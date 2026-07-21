#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1e9+7;
int n,f[200005];
char s[200005];
int main(){
	scanf("%d%s",&n,s+1);
	int flag=0;
	if(s[1]=='B')flag=1;
	f[1]=flag;
	int sum=0;
	if(f[1])sum++;
	for(int i=2;i<=2*n;i++){
		if(s[i]=='W'){
			if((flag+1)%2==0){
				f[i]=1;
				sum++;			
			}
			else{
				f[i]=0;
			}
			flag=!flag;
		}
		else{
			if((flag+1)%2==1){
				f[i]=1;
				sum++;
			}
			else{
				f[i]=0;
			}
			flag=!flag;
		}
		//cout<<f[i];
	}
	if(f[2*n]==1||sum!=n){
		printf("0");
		return 0;
	}
	//cout<<"aaa";
	ll ans=1;
	ll num=0;
	for(int i=1;i<2*n;i++){
		if(f[i]==1){
			num++;
		}
		else{
			ans=1ll*ans*num%mod;
			num--;
		}
	}
	for(int i=2;i<=n;i++)
		ans=1ll*ans*i%mod; 
	printf("%lld",(ans+mod)%mod);
}
