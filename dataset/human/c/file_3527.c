#include<stdio.h>
int main()
{
	int a,i,j,cnt=0,x[100];
	scanf("%d",&a);
	for(i=0;i<a;i++){
		scanf("%d",&x[i]);
	}
	for(i=a;i>0;i--){
		cnt=0;
		for(j=0;j<a;j++){
			if(i<=x[j]){
				cnt++;
			}
		}
		if(i<=cnt) break;
	}
	printf("%d\n",i);
	return 0;
}
