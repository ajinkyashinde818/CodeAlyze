#include<stdio.h>
#include<assert.h>
typedef long long ll;
const int mod=998244353;
int mul(int a,int b){return(ll)a*b%mod;}
void inc(int&a,int b){(a+=b)%=mod;}
int pow(int a,int b){
	int s=1;
	while(b){
		if(b&1)s=mul(s,a);
		a=mul(a,a);
		b>>=1;
	}
	return s;
}
int fac[4010],rfac[4010];
int C(int n,int k){
	if(!(0<=k&&k<=n))return 0;
	return mul(fac[n],mul(rfac[k],rfac[n-k]));
}
int main(){
	int k,n,i,m,p,q,s;
	scanf("%d%d",&k,&n);
	fac[0]=1;
	for(i=1;i<=k+n;i++)fac[i]=mul(fac[i-1],i);
	rfac[k+n]=pow(fac[k+n],mod-2);
	for(i=k+n;i>0;i--)rfac[i-1]=mul(rfac[i],i);
	for(i=2;i<=k*2;i++){
		s=0;
		if(i&1){
			if(i<=k)
				p=i/2;
			else
				p=(k-(i-k)+1)/2;
			m=k-2*p;
			for(q=0;q<=p;q++)inc(s,mul(mul(C(p,q),pow(2,q)),C(n+m-1,q+m-1)));
		}else{
			if(i<=k)
				p=i/2-1;
			else
				p=(k-(i-k))/2;
			m=k-2*p-1;
			for(q=0;q<=p;q++){
				inc(s,mul(mul(C(p,q),pow(2,q)),C(n+m-1,q+m-1)));
				inc(s,mul(mul(C(p,q),pow(2,q)),C(n+m-2,q+m-1)));
			}
		}
		printf("%d\n",s);
	}
}
