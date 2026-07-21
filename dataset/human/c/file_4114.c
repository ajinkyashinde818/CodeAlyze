#include <stdio.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)

int a,b,k,cnt;
int main(){
	scanf("%d%d%d",&a,&b,&k);
	for(int i=100;;i--)if(a%i==0&&b%i==0){
		cnt++;
		if(cnt==k){
			printf("%d",i);
			return 0;
		}
	}
}
