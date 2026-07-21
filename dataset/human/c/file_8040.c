#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
const int mod = 998344253;
typedef struct DLL_Node{
	int key;
	struct DLL_Node *prev, *next;
}Node;
Node *nil;
int H, W, Ch, Cw, Dh, Dw, d[1111][1111];
char s[1111][1111];
void push_front(int x){
	Node *z = (Node*)malloc(sizeof(Node));
	(*z).key=x;
	(*(*nil).next).prev = z;
	(*z).next = (*nil).next;
	(*nil).next = z;
	(*z).prev = nil;
	return;
}
void push_back(int x){
	Node *z = (Node*)malloc(sizeof(Node));
	(*z).key=x;
	(*(*nil).prev).next = z;
	(*z).prev = (*nil).prev;
	(*nil).prev = z;
	(*z).next = nil;
	return;
}
int front(){
	Node *t = (*nil).next;
	(*nil).next = (*(*nil).next).next;
	(*(*nil).next).prev = nil;
	int res = (*t).key;
	free(t);
	return res;
}
int main(){
	nil = (Node*)malloc(sizeof(Node));
	(*nil).next=(*nil).prev=nil;
	scanf("%d%d%d%d%d%d", &H, &W, &Ch, &Cw, &Dh, &Dw);
	Ch--; Cw--; Dh--; Dw--;
	for(int i=0; i<H; i++){
		scanf("%s", s[i]);
		for(int j=0; j<W; j++)d[i][j] = mod-1;
	}
	push_front(Ch * 10000 + Cw);
	d[Ch][Cw] = 0;
	while((*nil).next != nil){
		int tmp = front();
		int x = tmp/10000, y = tmp%10000;
		for(int i=-2; i<3; i++){
			for(int j=-2; j<3; j++){
				int nx = x+i, ny = y+j;
				if(0<=nx&&nx<H && 0<=ny&&ny<W && s[nx][ny]=='.'){
					int c = (abs(i)+abs(j)>1);
					int dis = d[x][y] + c;
					if(dis < d[nx][ny]){
						d[nx][ny] = dis;
						if(c){
							push_back(nx*10000 + ny);
						}else {
							push_front(nx*10000 + ny);
						}
					}
				}
			}
		}
	}
	printf("%d\n", (d[Dh][Dw]+1)%mod-1);
	//for(int i=0; i<H; i++){for(int j=0; j<W; j++)printf("%d", (d[i][j]+1)%mod-1);puts("");}
	return 0;
}
