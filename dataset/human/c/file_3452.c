#include<stdio.h>
#define MAXN 200005
int t[MAXN];
int u[MAXN];
int r[MAXN];
int main(){
	int a[MAXN],n,cnt = 0, p,m,total = 0;
	long long k;
	scanf("%d %lld",&n,&k);
	for(int i = 1; i <= n; i++){
		scanf("%d",&a[i]);
	}
	p = 1;
	u[1] = 1;
	t[0] = 1;
	do{
		cnt++;
		p = a[p];
		t[cnt] = p;
		if(u[p] == 0){
			u[p] = 1;
		}else break;
	}while(true);
	for(int i = 0; i < cnt; i++){
		if(t[i] == p){
			m = i;
			break;
		}
	}
	if(k < m){
		printf("%d\n",t[k]);
	}else{
	k = k - m;
	for(int i = m; i < cnt; i++){
		r[total++] = t[i];
	}
	k = k % total;
	printf("%d",r[k]);
	}
	return 0;
}
