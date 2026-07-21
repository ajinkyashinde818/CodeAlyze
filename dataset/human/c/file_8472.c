#include<stdio.h>
int main(void)
{
	int n, m,i,ai[1001],k,x,y,wk;
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;i++){
		scanf("%d",&ai[i]);
	}
	for(k=1;k<=m;k++){
		for(i=1;i<=n-1;i++){
			x=ai[i]%k;
			y=ai[i+1]%k;
			if(x>y){
				wk=ai[i];
				ai[i]=ai[i+1];
				ai[i+1]=wk;			
			}	
		}
	}
	for(i=1;i<=n;i++){
		printf("%d\n",ai[i]);
	}
	return 0;
}
