#include<stdio.h>
int main(void)
{
	int a[21],b[21],c[21],n,j,i,w;
	scanf("%d",&n);
	w=0;
	for(i=0;i<n;i++)	scanf("%d",&a[i]);
	for(i=0;i<n;i++){
		scanf("%d",&b[i]);
		w+=b[i];
		// printf("%d\n",w);
	}
	for(i=1;i<=n-1;i++)	scanf("%d",&c[i]);
	for(i=1;i<n;i++){
		if(a[i]-a[i-1]==1){
			w=c[a[i-1]]+w;
			// printf("%d\n",w);
		}
	}
	printf("%d\n",w);
	return 0;
}
