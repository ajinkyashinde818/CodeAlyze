#include <stdio.h>
#include <stdlib.h>
#include <stack>
#define MN 400000
int n,k,a[MN+5];
struct xxx{int p,c;};
struct STACK{
	xxx mem[MN+5];
	int tp;
	void clear(){tp=0;}
	void push(xxx x){mem[++tp]=x;}
	void pop(){--tp;}
	xxx& top(){return mem[tp];}
}q;
void spj(){
	for(int i=1;i<=n;i++)
		if(a[i]<=a[i-1]) return;
	puts("1");
	exit(0);
}
bool push(xxx x){
//	printf("push %d %d\n",x.p,x.c);
	if(x.p==0) return false;
	if(x.p==q.top().p){
		q.top().c++;
//		printf("%d ? %d\n",q.top().c,k);
		if(q.top().c==k+1){
			q.pop();
			if(q.top().p!=x.p-1) q.push((xxx){x.p-1,1});
			if(!push((xxx){x.p-1,1})) return false;
			q.push(x);
			return true;
		}
	}else{
		q.push(x);
	}
	return true;
}
bool check(){
//	puts("--");
	q.clear();
	for(int i=1;i<=n;i++){
		bool ex=false;
		while(q.top().p>a[i]) q.pop(),ex=true;
		if(ex&&q.top().p!=a[i]) q.push((xxx){a[i],1});
		if(!push((xxx){a[i],1})) return false;
	}
	return true;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	spj();
	int l=2,r=n,mid;
	while(l<=r){
		mid=(l+r)>>1; k=mid;
		if(check()) r=mid-1;
		else l=mid+1;
	}
	printf("%d\n",l);
}
