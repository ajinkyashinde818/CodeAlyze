#include<bits/stdc++.h>
int n,a[100007],b[100007],as[100007],ap=0;
int f[100007],sz[100007],deg[100007];
int gf(int x){
	while(x!=f[x])x=f[x]=f[f[x]];
	return x;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",a+i),a[0]^=a[i],as[ap++]=a[i];
	for(int i=1;i<=n;++i)scanf("%d",b+i),b[0]^=b[i];
	as[ap++]=a[0];
	std::sort(as,as+ap);
	ap=std::unique(as,as+ap)-as;
	for(int i=0;i<ap;++i)f[i]=i,sz[i]=0;
	for(int i=0;i<=n;++i)a[i]=std::lower_bound(as,as+ap,a[i])-as;
	for(int i=0;i<=n;++i){
		int x=std::lower_bound(as,as+ap,b[i])-as;
		if(x==ap||as[x]!=b[i])return puts("-1"),0;
		b[i]=x;
	}
	for(int i=0;i<=n;++i)if(a[i]!=b[i]||i==0){
		++deg[a[i]];--deg[b[i]];
		//printf("(%d->%d)",a[i],b[i]);
		int x=gf(a[i]),y=gf(b[i]);
		if(x!=y)f[y]=x,sz[x]+=sz[y];
		++sz[x];
	}
	for(int i=0;i<ap;++i)if(deg[i])return puts("-1"),0;
	int s=0,vv=gf(a[0]);
	for(int i=0;i<ap;++i)if(i==f[i]&&sz[i]){
		s+=sz[i]+1;
		if(i==vv)s-=2;
	}
	printf("%d",s);
	return 0;
}
