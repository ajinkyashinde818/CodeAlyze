#include <stdio.h>
#define Rep(i,a,n)for(int i=(int)(a);i<(int)(n);i++)
#define rep(i,n)Rep(i,0,n)
#define N 200010
int main() {
	int n,ch=1,start,end,a[N],b[N]={0},c[N];long long k;scanf("%d %lld",&n,&k);
	Rep(i,1,n+1)scanf("%d",&a[i]);
	Rep(i,1,N+10){
		if(b[ch]!=0){start=b[ch];end=i;break;}
		b[ch]+=i;
		ch=a[ch];
    }
	c[0]=ch;
	Rep(i,1,end-start+1) {
		c[i]=a[ch];
		ch=a[ch];
	}
	if (k<=start) {
		ch=1;
		rep(i,k)ch = a[ch];
		printf("%d",ch);
	}
	else if(end-start==1)printf("%d", ch);
	else{
		k-=start-1;
		k%=(end-start);
		printf("%d",c[k]);
	}
}
