#include <stdio.h>

char grid[55][55];
int grid2[55][55];

int main() {

	int H,W;

	scanf("%d %d",&H,&W);

	int i,j,k;

	for(i=0;i<H;i++){
		for(j=0;j<W;j++){
		scanf(" %c",&grid[i][j]);
		}
	}

	int dx[4]={1,0,-1,0};
	int dy[4]={0,1,0,-1};

	for(i=0;i<H;i++){
		for(j=0;j<W;j++){
			if(grid[i][j]=='#'){
			grid2[i][j]=1;
			for(k=0;k<4;k++){
				if(0<=i+dy[k]&&i+dy[k]<H&&0<=j+dx[k]&&j+dx[k]<W){
					if(grid[i+dy[k]][j+dx[k]]=='#'){
					grid2[i+dy[k]][j+dx[k]]=1;
					break;
					}
				}
			}
			if(k==4){
			printf("No\n");
			return 0;
			}
			}
		}
	}

	for(i=0;i<H;i++){
		for(j=0;j<W;j++){
			if((grid[i][j]=='.'&&grid2[i][j]==0) ||(grid[i][j]=='#'&&grid2[i][j]==1));
			else{printf("No\n");return 0;}
		}
	}

	printf("Yes\n");

return 0;
}
