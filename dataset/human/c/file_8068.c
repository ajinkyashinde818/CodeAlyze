#include <stdio.h>
long long ans;
int main(){
	long n;
	long long a[1000];
	long long b[1000];
	long long c[1000];
	long long d[1000];
	scanf("%li",&n);
	for (int i=1;i<=n;i++){
		scanf("%lli %lli %lli %lli",&a[i],&b[i],&c[i],&d[i]);	
		
	}
	for (int i=1;i<=n;i++){
		gcd(b[i],d[i]);
		long long g=ans;
		if (d[i]<b[i]||a[i]<b[i])printf("No\n");
		else
		if ((b[i]-g+a[i]%g)>c[i])printf("No\n");
		else printf("Yes\n");
	}
}
int gcd(long long x,long long y){
	if (x<y) return(gcd(y,x));
	if (x%y==0){
		ans=y;
		return(1);
	}
	return(gcd(y,x%y));
}
