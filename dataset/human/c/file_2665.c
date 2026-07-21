#include<stdio.h>
#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
int n,m,dui;
const int p=998244353;
long long f[11000],inv[11000],bi[11000],ans[11000];
inline long long qpow(int a,int n){
	long long x=a,ans=1;
	while (n){
		if (n&1) ans=ans*x%p;
		x=x*x%p;
		n>>=1;
	}
	return ans;
}
inline long long C(int n,int m){
	if (m<0||m>n) return 0;
	return f[n]*inv[m]%p*inv[n-m]%p;
}
inline int wor(int n,int dui,int num){
	int w=1;long long ans=0;
	fo(i,0,dui){//not use dui
		ans+=bi[dui-i]*C(dui,i)%p*C(n+dui-i+num-1,dui-i+num-1)%p*w;//C(n+dui+num-1,dui+num-1)
		w=-w;
	}
	return (ans%p+p)%p;
}
int main(){
	scanf("%d%d",&m,&n);
	bi[0]=1;
	fo(i,1,m){
		bi[i]=bi[i-1]<<1;
		if (bi[i]>=p) bi[i]-=p;
	}
	f[0]=inv[0]=1;
	fo(i,1,n+m) f[i]=f[i-1]*i%p; 
	inv[n+m]=qpow(f[n+m],p-2);
	fd(i,n+m-1,1) inv[i]=inv[i+1]*(i+1)%p;
	//fo(i,n+m-10,n+m) printf("%d\n",f[i]*inv[i]%p);
	fo(i,2,m+1){
		if (i&1){
			dui++;
			ans[i]=wor(n,dui,m-dui*2);	
		}else{
			ans[i]=wor(n,dui,m-dui*2-1)+wor(n-1,dui,m-dui*2-1);
			if (ans[i]>=p) ans[i]-=p;
		}
		printf("%lld\n",ans[i]);
	} 
	fd(i,m,2) printf("%lld\n",ans[i]);
	return 0;
}
