#include <stdio.h>
int n,x,i,j,k,a[101],b[101][101],ans=-99999;
int main(void){
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			scanf("%d",&x);
			a[j]=x+a[j-1];
		}
		for(j=1;j<=n;j++){
			for(k=j;k<=n;k++){
				b[j][k]+=a[k]-a[j-1];
				if(b[j][k]>ans)ans=b[j][k];
				if(b[j][k]<0)b[j][k]=0;
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}
