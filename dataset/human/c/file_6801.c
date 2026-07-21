#include<stdio.h>
#include<stdlib.h>

int compare_int(const void *a,const void *b){
	long long x=*(long long*)a;
	long long y=*(long long*)b;
	if(y>x)return 1;
	else if(x==y)return 0;
	else return -1;
}

#define N 300000

int main(){
	int n,i,c=0;
	long long a[N],ans=0;
	scanf("%d",&n);
	for(i=0;i<3*n;i++)scanf("%lld",&a[i]);
	qsort(a,3*n,sizeof(long long),compare_int);
	for(i=1;i<3*n;i+=2){
		if(c>=n)break;
		ans+=a[i];
		c++;
	}
	//for(i=0;i<n*3;i++)printf("%lld,",a[i]);
	printf("%lld\n",ans);
	return 0;
}
