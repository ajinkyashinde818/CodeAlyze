#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int n,i,p=1,t=0;
  int start=0;
	long long int k;
	long long int loop;
	int a[300000]={};
	int *b;
	b=(int*)malloc(sizeof(int)*300000);
	for(i=0;i<220000;i++){
		b[i]=0;
	}
	b[1]=1;
	(void)scanf("%d %lld",&n,&k);
	for(i=1;i<=n;i++){
		(void)scanf("%d",&a[i]);
	}
	for(i=0;i<k;i++){
		p=a[p];
		t++;
		if(b[p]!=0){
			start=p;
			break;
		}
		b[p]+=t;
	}
	k-=t;
	//printf("k is %lld\n",k);
	//printf("t is%d\n",t);
	//printf("start is %d\n",start);
	/*for(i=0;i<k;i++){
		p=a[p];
		b[p]+=1;
	}*/
	loop=t-b[start];
	if(start==1){
		loop++;
	}
	//printf("loop is %lld\n",loop);
	k=k%loop;
	for(i=0;i<k;i++){
		p=a[p];
	}
	printf("%d\n",p);
	free(b);
	return 0;
}
