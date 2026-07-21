#include <stdio.h>
#include <stdlib.h>

#define zh(x,y) ((y)*1000+(x))

int go(int,int,int,int,int,int,char[1000][1001]);

int main(int argc,char* argv[]) {
	/*declare values*/
	int h,w;
	int n;
	char map[1000][1001];
	int factpos[10][2];
	int x,y;
	int i;
	int timesum;
	/*do work*/
	scanf("%d %d %d",&h,&w,&n);
	for(i=0;i<h;i++)scanf("%s",map[i]);
	for(x=0;x<w;x++) {
		for(y=0;y<h;y++) {
			if(map[y][x]=='S') {
				factpos[0][0]=x;
				factpos[0][1]=y;
			} else if(map[y][x]>='1' && map[y][x]<='9') {
				factpos[map[y][x]-'0'][0]=x;
				factpos[map[y][x]-'0'][1]=y;
			}
		}
	}
	timesum=0;
	for(i=0;i<n;i++) {
		timesum+=go(factpos[i][0],factpos[i][1],
			factpos[i+1][0],factpos[i+1][1],h,w,map);
	}
	printf("%d\n",timesum);
	return 0;
}

int go(int sx,int sy,int dx,int dy,int h,int w,char map[1000][1001]) {
	int *zikan;
	int *togox;
	int *togoy;
	int *nexttogox;
	int *nexttogoy;
	int *tempp;
	int togonum;
	int nexttogonum;
	int x,y;
	int saitan=0;
	int i;
	zikan=calloc(1000*1000,sizeof(int));
	zikan[zh(sx,sy)]=1;
	/*É²×é×«ê*/
	togox=calloc(1000*1000,sizeof(int));
	togoy=calloc(1000*1000,sizeof(int));
	togonum=1;
	togox[0]=sx;
	togoy[0]=sy;
	/*»ÌÉ²×é×«ê*/
	nexttogox=calloc(1000*1000,sizeof(int));
	nexttogoy=calloc(1000*1000,sizeof(int));
	while(saitan==0) {
		nexttogonum=0;
		/*»ê¼êÌs«æð²×é*/
		for(i=0;i<togonum;i++) {
			x=togox[i];y=togoy[i];
			if(map[y][x]=='X')continue;
			if(x==dx && y==dy) {
				saitan=zikan[zh(x,y)]-1;
				break;
			}
			if(x>0) {
				if(zikan[zh(x-1,y)]==0) {
					nexttogox[nexttogonum]=x-1;
					nexttogoy[nexttogonum]=y;
					nexttogonum++;
					zikan[zh(x-1,y)]=zikan[zh(x,y)]+1;
				}
			}
			if(y>0) {
				if(zikan[zh(x,y-1)]==0) {
					nexttogox[nexttogonum]=x;
					nexttogoy[nexttogonum]=y-1;
					nexttogonum++;
					zikan[zh(x,y-1)]=zikan[zh(x,y)]+1;
				}
			}
			if(x<w-1) {
				if(zikan[zh(x+1,y)]==0) {
					nexttogox[nexttogonum]=x+1;
					nexttogoy[nexttogonum]=y;
					nexttogonum++;
					zikan[zh(x+1,y)]=zikan[zh(x,y)]+1;
				}
			}
			if(y<h-1) {
				if(zikan[zh(x,y+1)]==0) {
					nexttogox[nexttogonum]=x;
					nexttogoy[nexttogonum]=y+1;
					nexttogonum++;
					zikan[zh(x,y+1)]=zikan[zh(x,y)]+1;
				}
			}
		}
		/*|C^ÌüêÖ¦*/
		tempp=togox;
		togox=nexttogox;
		nexttogox=tempp;
		tempp=togoy;
		togoy=nexttogoy;
		nexttogoy=tempp;
		togonum=nexttogonum;
	}
	free(togox);
	free(togoy);
	free(nexttogox);
	free(nexttogoy);
	free(zikan);
	return saitan;
}
