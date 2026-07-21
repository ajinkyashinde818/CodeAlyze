#include<stdio.h>
#include<string.h>
#define NIL -1
struct tree {
	int father,brother,left,right,deep,height;
};
struct tree t[30];
int node,i,k;
//递归查询深度，先左子结点再右子结点，直到是叶子结点
void setDeep(int u,int deep) {
	t[u].deep=deep;
	if(t[u].left!=NIL) setDeep(t[u].left,deep+1);
	if(t[u].right!=NIL) setDeep(t[u].right,deep+1);
}
//递归查询高度 先找左子结点，再找右子结点，直到是叶子结点，开始返回记录高度，h1左方向，h2右方向
int setHeight(int u) {
	int h1=0,h2=0;
	if(t[u].left!=NIL) h1=setHeight(t[u].left)+1;
	if(t[u].right!=NIL) h2=setHeight(t[u].right)+1;
	return t[u].height=(h1<h2 ? h2:h1);
}

int main() {
	int n,l,r;
	scanf("%d",&node);
	memset(t,-1,sizeof(t));
	for(i=0; i<node; i++) {
		scanf("%d%d%d",&n,&l,&r);
		t[n].left=l;
		t[n].right=r;
		t[l].father=n;
		t[l].brother=r;
		t[r].father=n;
		t[r].brother=l;
	}
	int root=0;
	for(k=0; k<node; k++)
		if(t[k].father==NIL) root=k;
	setDeep(root,0);
	setHeight(root);

	for(k=0; k<node; k++) {
		printf("node %d: parent = %d, sibling = %d, ",k,t[k].father,t[k].brother);
		if(t[k].left!=-1&&t[k].right!=-1) printf("degree = 2, ");
		else if(t[k].left!=-1||t[k].right!=-1) printf("degree = 1, ");
		else printf("degree = 0, ");
		printf("depth = %d, height = %d, ",t[k].deep,t[k].height);
		if(t[k].father==NIL) printf("root\n");
		else if(t[k].left==-1&&t[k].right==-1) printf("leaf\n");
		else printf("internal node\n");
	}
	return 0;
}
