#include<stdio.h>
#include<string.h>

#define MAX 1000

int top,bottom;

typedef struct{
	int x;
	int y;
	int cost;
}queue;
queue q[500000];
char map[MAX+2][MAX+2];
int visited[MAX+2][MAX+2];

void init(){
	int i,j;
	for(i=0;i<MAX+2;i++){
		for(j=0;j<MAX+2;j++){
			visited[i][j]=0;
		}
	}
}
void push(int x,int y,int cost){
	q[top].x=x;
	q[top].y=y;
	q[top].cost=cost;
	top++;
}
queue* pop(void){
	if(top==bottom){return NULL;}
	return &q[bottom++];
}

int main(){
	int h,w,n;
	int i;
	int ans=0;
	int list[10][2];//探索リスト
	int vector[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
	scanf("%d %d %d",&h,&w,&n);
	for(i=0;i<h+2;i++){
		if(i==0||i==h+1){
			memset(map[i],'X',w+2);
		}else{
			int j;
			scanf("%s",&map[i][1]);
			map[i][0]='X';
			map[i][w+1]='X';
			if(strchr(map[i],'S')!=NULL){
				list[0][0]=i;
				list[0][1]=(strchr(map[i],'S')-map[i]);
			}
			for(j=0;j<w+2;j++){
				char* p=(strchr(map[i],'0'+j));
				if(p!=NULL){
					list[j][0]=i;
					list[j][1]=p-map[i];
				}
			}
		}
	}
	for(i=0;i<n;i++){
		init();
		top=0;bottom=0;
		push(list[i][0],list[i][1],0);//スタート地点
		while(1){
			int j;
			queue* now;
			now=pop();
			if(now->x==list[i+1][0]&&now->y==list[i+1][1]){//到達したか否か
				ans+=now->cost;				
				break;
			}
			for(j=0;j<4;j++){
				int next_x=now->x+vector[j][0];
				int next_y=now->y+vector[j][1];
				if(map[next_x][next_y]!='X'&&visited[next_x][next_y]!=1){
					visited[next_x][next_y]=1;
					push(next_x,next_y,now->cost+1);
				}
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}
