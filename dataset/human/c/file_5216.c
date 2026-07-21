#include<stdio.h>
#include<stdlib.h>

typedef struct box{
	int par;//親の接点番号
	int left;//子（左）
	int right;//子（右）
} Node;

void preorder(Node *node)
{
	
}

int depthsearch(Node *node,int point)//深さを返す
{
	int i,cnt=0,current = point;
	while(node[current].par!=-1){
		current=node[current].par;
		cnt++;
	}
	
	return cnt;
}

int heightsearch(Node *node,int point)//高さを返す
{
	int l=0,r=0;
	if(node[point].right!=-1) r=heightsearch(node,node[point].right)+1;
	if(node[point].left!=-1) l=heightsearch(node,node[point].left)+1;
	
	if(r>l) return r;
	else return l;
}

int siblingsearch(Node *node,int point)//兄弟番号を返す
{
	int box;
	box=node[point].par;
	if(box==-1) return -1;
	if(node[box].left==point) return node[box].right;
	else return node[box].left;
}

int degreesearch(Node *node,int point)//子の個数を返す
{
	int cnt=0;
	if(node[point].left!=-1) cnt++;
	if(node[point].right!=-1) cnt++;
	
	return cnt;
}


int main(void)
{
	int i,j,n;
	int box,s;
	Node *node;
	
	scanf("%d",&n);
	node=(Node*)malloc(sizeof(Node)*n);
	for(i=0;i<n;i++) node[i].par=-1;//親の節点番号を初期化
	for(i=0;i<n;i++){
		scanf("%d",&box);
		scanf("%d",&node[box].left);
		node[node[box].left].par=box;
		scanf("%d",&node[box].right);
		node[node[box].right].par=box;
	}
	
	
	
	for(i=0;i<n;i++){
		printf("node %d: parent = %d, ",i,node[i].par);
		printf("sibling = %d, degree = %d, ",siblingsearch(node,i),degreesearch(node,i));
		printf("depth = %d, height = %d, ",depthsearch(node,i),heightsearch(node,i));
		if(node[i].par==-1) printf("root");
		else if(node[i].left==-1&&node[i].right==-1) printf("leaf");
		else printf("internal node");
		printf("\n");
	}
	
	free(node);
	
	return 0;
}
