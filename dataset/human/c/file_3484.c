#include<stdio.h>
#include<stdlib.h>

typedef unsigned long long ull;

int main(void){
	int n,i,j;
	int *nextTown,*visited;
	int nowTown,prevTown,visitedCount,ans,loopCount;
	ull k;
	scanf("%d%llu",&n,&k);
	nextTown=(int *)calloc(n+1,sizeof(int));
	visited=(int *)calloc(n+1,sizeof(int));
	for(i=1;i<=n;i++){
		scanf("%d",&nextTown[i]);
	}
	nowTown=1;
	prevTown=0;
	visitedCount=1;
	while(visited[nowTown]==0 && visitedCount<=k){
		//printf("%d: nowTown= %d\n",visitedCount,nowTown);
		visited[nowTown]=visitedCount;
		visitedCount++;
		prevTown=nowTown;
		nowTown=nextTown[prevTown];
	}
	//puts("Loop detected");
	if(visitedCount<=k){
		//printf("nowTown: %d\n",nowTown);
		loopCount=visitedCount-visited[nowTown];
		k-=visitedCount-1;
		k%=loopCount;
		//printf("k: %d\n",k);
		for(i=0;i<k;i++){
			prevTown=nowTown;
			nowTown=nextTown[prevTown];
		}
	}
	printf("%llu\n",nowTown);
	free(nextTown);
	free(visited);
}
