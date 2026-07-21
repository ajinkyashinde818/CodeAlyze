#include <stdio.h>
#include <string.h>

int shelf_max;
int result[10001][3];
char map[40004];
char map2[10001];

/*prev now status*/
const int costs[3][3][4]={
	{
		{0,1,3,3},
		{1,1,2,2},
		{2,2,2,2}
	},{
		{1,1,2,2},
		{0,1,1,2},
		{1,2,1,2}
	},{
		{2,2,2,2},
		{1,2,1,2},
		{0,3,1,3}
	}
};

int main(void) {
	int case_num;
	int i,j,k;
	int now_min;
	scanf("%d",&case_num);
	for(i=0;i<case_num;i++) {
		scanf("%d",&shelf_max);
		scanf("%s",map);
		memset(result,0,sizeof(result));
		memset(map2,0,sizeof(map2));
		if(map[0]=='Y')map2[0]|=1;
		if(map[shelf_max*2]=='Y')map2[0]|=2;
		for(j=1;j<shelf_max;j++) {
			if(map[j*2-1]=='Y' || map[j*2]=='Y')map2[j]|=1;
			if(map[shelf_max*2+j*2-1]=='Y' ||
				map[shelf_max*2+j*2]=='Y')map2[j]|=2;
		}
		if(map[shelf_max*2-1]=='Y')map2[shelf_max]|=1;
		if(map[shelf_max*4-1]=='Y')map2[shelf_max]|=2;
		result[0][0]=costs[0][0][map2[0]];
		result[0][1]=costs[0][1][map2[0]];
		result[0][2]=costs[0][2][map2[0]];
		for(j=1;j<=shelf_max;j++) {
			for(k=0;k<3;k++) {
				now_min=0x7fffffff;
				if(now_min>result[j-1][0]+costs[0][k][map2[j]])
					now_min=result[j-1][0]+costs[0][k][map2[j]];
				if(now_min>result[j-1][1]+costs[1][k][map2[j]])
					now_min=result[j-1][1]+costs[1][k][map2[j]];
				if(now_min>result[j-1][2]+costs[2][k][map2[j]])
					now_min=result[j-1][2]+costs[2][k][map2[j]];
				result[j][k]=now_min+1;
			}
		}
		now_min=result[shelf_max][0];
		if(now_min>result[shelf_max][1]+1)
			now_min=result[shelf_max][1]+1;
		if(now_min>result[shelf_max][2]+2)
			now_min=result[shelf_max][2]+2;
		printf("%d\n",now_min);
	}
	return 0;
}
