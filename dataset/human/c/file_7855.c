#include<stdio.h>
#include<string.h>
typedef struct point{
	int x,y;
}POINT;
POINT q[5000],sq[5000],g[15],s,c;
int qn,sqn;
char m[1005][1005],m2[1005][1005],x[1005];
int main(){
	int i,j,k,h,w,n,ans;
	int dx[4]={0,1,0,-1},dy[4]={-1,0,1,0};
	FILE *fp;
	//fp=fopen("test.txt","r");
	fp=stdin;
	fscanf(fp,"%d%d%d",&h,&w,&n);
	for(i=0;i<=h+1;i++){
		if(i==0 || i==h+1){
			for(j=0;j<=w+1;j++)m[i][j]='X';
		}else{
			fscanf(fp,"%s",x);
			for(j=0;j<w;j++){
				if(x[j]>='1' && x[j]<='9'){
					g[x[j]-'0'].x=j+1;
					g[x[j]-'0'].y=i;
				}else if(x[j]=='S'){
					//s.x=j;s.y=i;
					g[0].x=j+1;g[0].y=i;
				}
			}
			//sprintf(m[i],"X%sX",x);
			strcat(m[i]+1,x);
			m[i][0]=m[i][w+1]='X';
		}
		//printf("%s\n",m[i]);
	}
	ans=0;
	memcpy(m2,m,sizeof(m));
	for(k=1;k<=n;k++){
		q[0].x=s.x=g[k-1].x;
		q[0].y=s.y=g[k-1].y;
		m[q[0].y][q[0].x]='X';
		qn=1;
		while(qn){
			sqn=0;
			for(i=0;i<qn;i++){
				m[q[i].y][q[i].x]='X';
				if(q[i].x==g[k].x && q[i].y==g[k].y)goto nex;
				for(j=0;j<4;j++){
					c.x=q[i].x+dx[j];
					c.y=q[i].y+dy[j];
					if(m[c.y][c.x]!='X'){
						sq[sqn].x=c.x;
						sq[sqn].y=c.y;
						sqn++;
						m[c.y][c.x]='X';
					}
				}
			}
			memcpy(q,sq,sizeof(POINT)*sqn);
			qn=sqn;
			ans++;
		}
		nex:
		//printf("%d\n",ans);
		memcpy(m,m2,sizeof(m2));
	}
	printf("%d\n",ans);
	fclose(fp);
	return 0;
}
