#include <stdio.h>
int main(void){
	int n,i,a[100001],b,c=0;
	scanf("%d",&n);
	for(i=0;i<n;i++){scanf("%d",&a[i]);}
	i=0;
	while(c<n){
		b=a[i]- 1;
		c++;
		if(b==1){printf("%d",c);return 0;}
		i=b;
	}
	printf("-1");
	return 0;
}
