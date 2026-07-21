#include<stdio.h>
int main(void)
{
    int n,k[1001],p[1001],x[1001],i;
	scanf("%d",&n);
	for(i=0;i<n;i++){
	    scanf("%d %d",&k[i],&p[i]);
		x[i]=k[i]%p[i];
	}
	for(i=0;i<n;i++){
	    if(x[i]==0){
		    printf("%d\n",p[i]);
		}
		else if(x[i]==k[i]){
		    printf("%d\n",k[i]);
		}
		else {
		    printf("%d\n",x[i]);
		}
	}
	return 0;
}
