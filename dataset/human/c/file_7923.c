#include <stdio.h>
#include <string.h>

int N;
int count[20];
int rinsetu[20][20];
int maxtime;

void tansaku(int prev,int now,int nowtime) {
	int i;
	if(nowtime>maxtime)maxtime=nowtime;
	for(i=0;i<N;i++) {
		if(i!=prev && rinsetu[now][i]>0)tansaku(now,i,nowtime+rinsetu[now][i]);
	}
}

int main(void) {
	int i,j;
	int timesum;
	while(scanf("%d",&N)==1 && N>0) {
		memset(rinsetu,0,sizeof(rinsetu));
		memset(count,0,sizeof(count));
		for(i=1;i<N;i++) {
			int a,b,t;
			scanf("%d%d%d",&a,&b,&t);
			a--;b--;
			rinsetu[a][b]=rinsetu[b][a]=t;
			count[a]++;count[b]++;
		}
		for(i=1;i<N;i++) {
			if(count[i]==1) {
				for(j=0;j<N;j++) {
					rinsetu[i][j]=rinsetu[j][i]=0;
				}
			}
		}
		timesum=0;
		for(i=0;i<N;i++) {
			for(j=i+1;j<N;j++)timesum+=rinsetu[i][j];
		}
		timesum*=2;
		maxtime=0;
		tansaku(-1,0,0);
		timesum-=maxtime;
		printf("%d\n",timesum);
	}
	return 0;
}
