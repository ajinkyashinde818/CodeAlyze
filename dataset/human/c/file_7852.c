#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define recp(I,Y,X) {q[I].x=X;q[I].y=Y;m[Y][X]='X';I++;}
char m[1005][1005],m2[1005][1005];
typedef struct point{
	int x,y;
}POINT;
POINT sq[500],q[500],g[11];
int h,w,n,i,j,ans=0,gx,gy,cx,cy,sqn,qn;
int main(){
	char s[1005];
	scanf("%d%d%d",&h,&w,&n);
	for(i=0;i<=w+1;i++)m[0][i]=m[h+1][i]='X';
	for(i=1;i<=h;i++){
		scanf("%s",s);
		strcat(m[i]+1,s);
		for(j=1;j<=w;j++){
			if(m[i][j]=='S')g[0].y=i,g[0].x=j;
			else if(m[i][j]!='.' && m[i][j]!='X')g[m[i][j]-'0'].y=i,g[m[i][j]-'0'].x=j;
		}
		m[i][0]=m[i][w+1]='X';
	}
	memcpy(m2,m,sizeof(m));
	for(i=1;i<=n;i++){
		sq[0].x=g[i-1].x,sq[0].y=g[i-1].y;
		m[g[i-1].y][g[i-1].x]='X',gx=g[i].x,gy=g[i].y;sqn=1;
		//printf("%d %d\n",sq[0].y,sq[0].x);
		//printf("%d %d\n",gy,gx);
		while(sqn){
			qn=0;
			//printf("\n");
			for(j=0;j<sqn;j++){
				cx=sq[j].x;cy=sq[j].y;
				//printf("%d %d\n",cy,cx);
				if(cx==gx && cy==gy)goto nex;
				if(m[cy-1][cx]!='X')recp(qn,cy-1,cx);
				if(m[cy+1][cx]!='X')recp(qn,cy+1,cx);
				if(m[cy][cx-1]!='X')recp(qn,cy,cx-1);
				if(m[cy][cx+1]!='X')recp(qn,cy,cx+1);
			}
			memcpy(sq,q,sizeof(POINT)*qn);
			//printf("%d\n",qn);
			sqn=qn;
			ans++;
		}
		nex:
		memcpy(m,m2,sizeof(m2));
	}
	printf("%d\n",ans);
	return 0;
}
