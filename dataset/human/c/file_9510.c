#include <stdio.h>
#include <string.h>

int main(void){
	int i,n,d,x,a[100],j,c;
	scanf("%d %d %d",&n,&d,&x);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	for(i=0;i<n;i++){
		j=0;
		c=0;
		while(c<=d){
			x++;
			c=1+a[i]*j;
			j++;
			//printf("%d\n",c);
		}
		//printf("%d\n",x);
	}
	printf("%d\n",x-n);
	return 0;
}
