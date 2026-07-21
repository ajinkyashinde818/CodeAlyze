/*Lucky_Glass*/
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int N=1e5;
const long long MOD=(long long)1e9+7;

int n;
char str[2*N+10];
int tmp[2*N+10];
long long an$s,fac;

int main(){
	scanf("%d%s",&n,str+1);
	n*=2;
	int cnt=0;an$s=fac=1;
	for(int i=1;i<=n;i++){
		if(2*i<=n) fac=fac*i%MOD;
		if(tmp[i]) continue;
		if((cnt&1)^(str[i]=='W')){
			if(!cnt){
				printf("0\n");
				return 0;
			}
			an$s=an$s*cnt%MOD;
			cnt--;
		}
		else
			cnt++;
	}
	if(cnt){
		printf("0\n");
		return 0;
	}
	printf("%lld\n",fac*an$s%MOD);
	return 0;
}
