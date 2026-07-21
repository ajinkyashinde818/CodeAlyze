#include<stdio.h>
int n,i,a,s,x,of,bh[100001],bf[100001];
int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&a);
		bh[i]=a;
	}
	
	x=1;
	while(1){
		s++;
		bf[x]++;
		if(bf[x]>=2){
			of=1;
			break;
		}
		x=bh[x];
		if(x==2)break;
	}
	
	if(of==1)printf("-1\n");
	else printf("%d\n",s);
	
	return 0;
}
