#include<stdio.h>
int main(void){
	int n,a,b;
	int i,j,cnt;
	scanf("%d\n",&n);
	for(i=0;i<n;i++){
		cnt=0;
		scanf("%d %d",&a,&b);
		while(a>0){
			for(j=1;j<=b;j++){
				a--;
				if(a==0){
					break;
				}
			}
		}
		printf("%d\n",j);
	}
	return 0;
}
