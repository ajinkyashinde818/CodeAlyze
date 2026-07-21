#include <stdio.h>
int max(int a,int b){ return a<b?b:a;}
int min(int a,int b){ return a>b?b:a;}
int n,xs=1e9,ys=1e9,xb=-1e9,yb=-1e9,ret=1e9,x[100005],y[100005],v;
int main(){
	scanf("%d",&n);
	for(int i=0,a,b;i<n;i++){
		scanf("%d%d",&a,&b);
		x[i]=a-b; y[i]=a+b;
		xs=min(xs,x[i]); xb=max(xb,x[i]);
		ys=min(ys,y[i]); yb=max(yb,y[i]);
	}
	for(int i=0;i<n;i++) v=max(v,min(max(x[i]-xs,y[i]-ys),max(xb-x[i],yb-y[i]))); ret=min(ret,v);v=0;
	for(int i=0;i<n;i++) v=max(v,min(max(x[i]-xs,yb-y[i]),max(xb-x[i],y[i]-ys)));
	ret=min(ret,v);
	printf("%d\n",ret);
}
