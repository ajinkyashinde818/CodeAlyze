#include<stdio.h>
typedef long long ll;
const int mod=1000000007;
int mul(int a,int b){return(ll)a*b%mod;}
int a[100010],d[100010],p[100010],f[100010],c[100010];
bool v[100010];
int main(){
	int n,i,j,c1,c2,ans;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",a+i);
		d[a[i]]++;
	}
	#define wrong {putchar('0');return 0;}
	ans=1;
	for(i=1;i<=n;i++){
		if(d[i]>2)wrong
		if(v[i]||d[i]<2)continue;
		j=i;
		do{
			if(v[j])wrong
			v[j]=1;
			p[a[j]]=j;
			j=a[j];
		}while(j!=i);
	}
	for(i=1;i<=n;i++){
		if(d[i]==0){
			c1=0;
			for(j=i;d[j]!=2;j=a[j]){
				c1++;
				v[j]=1;
			}
			c2=1;
			for(j=p[j];d[j]!=2;j=p[j])c2++;
			if(c1>c2)wrong
			if(c1<c2)ans=mul(ans,2);
		}
	}
	for(i=1;i<=n;i++){
		if(!v[i]){
			c1=0;
			j=i;
			do{
				v[j]=1;
				j=a[j];
				c1++;
			}while(j!=i);
			c[c1]++;
		}
	}
	for(i=1;i<=n;i++){
		c1=1+(i!=1&&(i&1));
		f[0]=1;
		f[1]=c1;
		for(j=2;j<=c[i];j++)f[j]=(mul(f[j-2],mul(j-1,i))+mul(f[j-1],c1))%mod;
		ans=mul(ans,f[c[i]]);
	}
	printf("%d",ans);
}
