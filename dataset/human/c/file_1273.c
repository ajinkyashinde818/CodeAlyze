#include<stdio.h>

int main(void)
{
	int p[8];
	int q[8]={1,2,1,2,1,4,1,4};
	int ans[8][8];
	int waitnum[8];
	while(1){
		for(int i=0;i<8;i++){
			if(scanf("%d",&p[i])==EOF){
				return 0;
			}
		}
		for(int i=0;i<8;i++){	//iは回答のナンバー　並べ方
			for(int j=0;j<8;j++){
				ans[i][j]=q[(i+j)%8];
			}
			waitnum[i]=0;
			for(int j=0;j<8;j++){
				int tmp=p[j]-ans[i][j];
				if(tmp<=0){
					tmp = 0;
				}
				waitnum[i]+=tmp;
			}
		}
		int min=0;
		for(int i=1;i<8;i++){
			if(waitnum[i]<waitnum[min]){
				min=i;
			}
			else if(waitnum[i]==waitnum[min]){
				for(int j=0;j<8;j++){
					if(ans[i][j]<ans[min][j]){
						min=i;
						break;
					}else if(ans[i][j]>ans[min][j]){
						break;
					}
				}
			}
		}
		printf("%d",ans[min][0]);
		for(int i=1;i<8;i++){
			printf(" %d",ans[min][i]);
		}
		printf("\n");
	}
	return 0;
}
