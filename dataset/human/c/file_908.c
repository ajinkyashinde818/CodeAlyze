#include<stdio.h>
int bit[100001];
int n;
void add(int i,int x){
	while(i<=n){
		bit[i]+=x;
		i+=i&-i;
	}
}

int sum(int i){
	int s=0;
	while(i>0){
		s+=bit[i];
		i-=i&-i;
	}
	return s;
}

int main(){
	int i;
	scanf("%d",&n);
	for(i=0;i<=n;i++)bit[i]=0;
	for(i=0;i<n;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		a--;b--;
		add(a,1);
		add(b+1,-1);
	}
	int ans=0;
	for(i=1;i<=n;i++)if(sum(i)>=i)ans=i;
	printf("%d\n",ans);
	return 0;
}
