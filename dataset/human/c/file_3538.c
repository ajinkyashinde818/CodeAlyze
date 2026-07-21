#include<stdio.h>
int main(void)
{
	int n,p[100],i,j,cnt,max;
	scanf("%d",&n);
	max=0;
	for(i=0;i<n;i++){
		scanf("%d",&p[i]);
	}
	for(i=1;i<=n;i++){
		for(j=0;j<n;j++){
			if(i<=p[j]){
				cnt++;
			}
		}
		if(i<=cnt && i>max){
			max=i;
		}
		cnt=0;
	}
	printf("%d\n",max);
	return 0;
}
