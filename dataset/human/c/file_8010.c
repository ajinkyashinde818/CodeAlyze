#include<stdio.h>
#define mod 1000000007

long long modiv(long long a,long long b){
	if(b==0)return 1;
	if(b%2)return (a*modiv(a,b-1))%mod;
	long long i;
	i=modiv(a,b/2);
	return (i*i)%mod;
}

long long ncm(int a,int b){
	long long r1=1,r2=1,r3=1,i;
	for(i=a;i>0;i--)r1*=i,r1%=mod;
	for(i=b;i>0;i--)r2*=i,r2%=mod;
	for(i=a-b;i>0;i--)r3*=i,r3%=mod;
	r2=(r2*r3)%mod;
	long long r=(r1*modiv(r2,mod-2));
	return (r+mod)%mod;
}

int main(){
	int x,y,i;
	long long ans=0;
	scanf("%d%d",&x,&y);
	if((x+y)%3!=0)puts("0");
	else{
		int a=(x+y)/3;
		if(a%2==0){
			int ax=(a/2)*3;
			int ay=ax;
			for(i=0;i<=a/2;i++){
				if(x==ax+i&&y==ay-i){
					printf("%lld\n",ncm(a,a/2-i));
					return 0;
				}if(x==ax-i&&y==ay+i){
					printf("%lld\n",ncm(a,a/2-i));
					return 0;
				}
			}
			puts("0");
			return 0;
		}else{
			int ax=(a/2)*3+2,ay=(a/2)*3+1;
			for(i=0;i<=a/2;i++){
				if(x==ax+i&&y==ay-i){
					printf("%lld\n",ncm(a,a/2-i));
					return 0;
				}if(y==ax+i&&x==ay-i){
					printf("%lld\n",ncm(a,a/2-i));
					return 0;
				}
			}
			puts("0");
			return 0;
		}
	}
	return 0;
}
