#include<stdio.h>
int n,i;
int a[300000],b[300000],c[300000],d[300000];
int main(){
	scanf("%d",&n);
	for (i=1;i<=n;i++)
	  scanf("%d",&a[i]);
	for (i=1;i<=n;i++)
	  scanf("%d",&b[i]);
	for (i=1;i<=n;i++)
	  c[i]=b[n-i+1];
	int flag=1;
	for (i=1;i<=n;i++)
	  if (c[i]==a[i])
	    flag=0;
	if (flag==1){
		printf("Yes\n");
		for (i=1;i<=n;i++)
		  printf("%d ",c[i]);
		return 0;
	}
	for (i=1;i<=n;i++)
	  d[(i+n/2)%n+1]=b[i];
	flag=1;
	for (i=1;i<=n;i++)
	  if (d[i]==a[i])
	    flag=0;
	if (flag==1){
		printf("Yes\n");
		for (i=1;i<=n;i++)
		  printf("%d ",d[i]);
		return 0;
	}
	printf("No");
}
