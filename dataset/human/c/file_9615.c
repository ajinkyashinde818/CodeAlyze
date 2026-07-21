#include<stdio.h>

	struct data{
		char n[9];
		int m;
	}d[100];
int main(){
	int n,m;
	char N[100][9];
	int M[1000];
	int i,j,k;
	char b[1000][9];
	int ans=0;
	int flag = 0;

	while(scanf("%d%d",&n,&m),n+m){
		ans=0;
		flag = 0;
		for(i =0;i<n;i++){
			scanf("%s%d",d[i].n,&d[i].m);
		}
		for(i =0;i<m;i++){
			scanf("%s",b[i]);
		}
	for(k=0;k<n;k++){
		for(i =0;i<m;i++){
			flag = 0;
			for(j=0;j<8;j++){
				if(d[k].n[j] != '*'){
					if(d[k].n[j] == b[i][j]){
						flag = 2;
					}else{
						flag = 1;
					}
				}else{
					flag = 1;
					continue;
				}
				if(flag == 1){
					break;
				}
			}
			if(flag == 2){
				ans += d[k].m;
			}
		}
	}
		printf("%d\n",ans);
	}
	return 0;
}
