#include<stdio.h>
#include<math.h>

int main(void){
	int n,m,x;
	scanf("%d %d %d",&n,&m,&x);
	
	int c[n];
	int a[n][m];
	for(int i=0;i<n;i++){
		scanf("%d",&c[i]);
		for(int j=0;j<m;j++){
			scanf("%d",&a[i][j]);
		}
	}
	
	
	int keisan[m+1];
	int min_hairetu;
	int min_daikin=2147483647;
	
	for(int i=1;i<pow(2,n);i++){
		min_hairetu=2147483647;
		for(int j=0;j<m;j++){
			keisan[j]=0;
			for(int k=0;k<n;k++){
				if(i&(1<<k)){
					keisan[j]+=a[k][j];
				}
			}
			min_hairetu<keisan[j]?1:(min_hairetu=keisan[j]);
		}
		
		if(min_hairetu>=x){
			keisan[m]=0;
			for(int k=0;k<n;k++){
				if(i&(1<<k)){
					keisan[m]+=c[k];
				}
			}
			min_daikin<keisan[m]?1:(min_daikin=keisan[m]);
		}
	}
	
	if(min_daikin!=2147483647){
		printf("%d",min_daikin);
	}else{
		printf("-1");
	}
	
}
