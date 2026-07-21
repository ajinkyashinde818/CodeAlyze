#include <stdio.h>

int main(){
	int m,n;
	int i,j,k,l;
	int found,end;
	scanf("%d %d",&n,&m);
	
	char M[m][m];
	char N[n][n];
	
	for(i=0;i<n;i++) scanf("%s",N[i]);
	for(i=0;i<m;i++) scanf("%s",M[i]);

	end = 0;
	for(i=0;i<=n-m&&end==0;i++){
		for(j=0;j<=n-m&&end==0;j++){
			found = 1;
			for(k=0;k<m&&found==1;k++){
				for(l=0;l<m&&found==1;l++){
					//printf("%d,%d(%c),%d,%d(%c)\n",i+k,j+l,N[i+k][j+l],k,l,M[k][l]);
					if(N[i+k][j+l]!=M[k][l]) found = 0;
				}
			}
			if(found == 1){
				end = 1;
				break;	
			}
		}
	}
	
	if(found == 1){
		printf("Yes\n");
	}else{
		printf("No\n");
	}
	return 0;
}
