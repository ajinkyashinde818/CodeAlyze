#include<stdio.h>

int m,n;
int thickness[100];

int ok(int x){
	int i,j=0,w;
	for(i=0;i<m;i++){
		w=x;
		while(j<n&&thickness[j]<=w)w-=thickness[j++];
		if(j==n)break;
	}
	return j==n;
}
int main(){
	int i,l,mid,r;
	while(scanf("%d%d",&m,&n)==2&&(m||n)){
		for(i=0;i<n;i++)scanf("%d",&thickness[i]);
		l=1;r=1500000;
		while(1<r-l){
			mid=(l+r)/2;
			if(ok(mid))r=mid;
			else l=mid;
		}
		printf("%d\n",r);
	}
}
