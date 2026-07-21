#include<stdio.h>
int a[400000];
int visit[400000];
int cur,num,i,record,n;
long long k,t,cycle;
int main(){
	scanf("%d %lld",&n,&k);
	for (i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for (i=1;i<=n;i++) visit[i]=0;
	cur=1;num=0;
	while (1==1){
		num++;
		cur=a[cur];
		if (visit[cur]!=0)
		{record=cur;
		 break;
		}else{
			visit[cur]=num;
		}
	}
	cycle=num-visit[record];
	if (k<=visit[record]){
		cur=1;
		for (i=1;i<=k;i++)
		  cur=a[cur];
		printf("%d",cur);
	}else{
		t=(k-(visit[record]-1))%cycle;
		if (t==0) t=cycle;
		cur=1;
		for (i=1;i<=visit[record]-1+t;i++)
		  cur=a[cur];
		printf("%d",cur);
	}
}
