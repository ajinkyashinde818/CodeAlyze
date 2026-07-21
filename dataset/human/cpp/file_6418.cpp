#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <map>
#include <vector>
#include <cstring>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 10;
const int mod = 1e9 + 7;
char s[maxn<<1];
int main(){
	int n;scanf("%d",&n);
	scanf("%s",s+1);
	int count = 0;
	ll ans=1;
	for(int i=1;i<=n;i++){
		ans=(ans*i)%mod;
	}
	for(int i=1;i<=2*n;i++){
		if(count&1){
			if(s[i]=='B'){
				if(count>0){
					
					ans=(ans*count)%mod;
					count--;
				}
				else{
					puts("0");
					return 0;
				}
			}
			else if(s[i]=='W'){
				count++;
			}
		}
		else{
			if(s[i]=='W'){
				if(count>0){
			
					ans=(ans*count)%mod;
					count--;
				}
				else{
					puts("0");
					return 0;
				}
			}
			else if(s[i]=='B'){
				count++;
			}
		}
	}
	if(count) ans=0;
	printf("%lld\n",ans%mod);
}
