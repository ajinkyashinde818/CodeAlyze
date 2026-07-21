#include<stdio.h>

int main(){
	char ss[9],to[100][9];
	int tok[100];
	int i,j,n,m,kin,k,flag;
	
	while(~scanf("%d%d",&n,&m)){
		if(n==0)break;
		kin=0;
		
		for(i=0;i<n;i++){
			scanf(" %s ",to[i]);
			scanf("%d",&tok[i]);
//			printf("%s %d\n",to[i],tok[i]);
		}
		
		
		for(i=0;i<m;i++){
			scanf(" %s ",ss);
			
			for(j=0;j<n;j++){
				flag=0;
				for(k=0;k<8;k++){
					if(to[j][k]=='*')continue;
					if(to[j][k]!=ss[k])flag=1;
				}
				if(flag==0)kin+=tok[j];
			}
		}
		printf("%d\n",kin);
	}
	return 0;
}
