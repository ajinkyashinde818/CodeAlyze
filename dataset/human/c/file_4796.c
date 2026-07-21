#include<stdio.h>
#define MAX 30
#define NIL -1
struct node{
	int p,l,r;
}; 
struct node t[MAX];
int dep[MAX],hei[MAX];
void setDepth(int u,int d){
	dep[u]=d;
	if(t[u].l!=NIL)
	setDepth(t[u].l,d+1);
	if(t[u].r!=NIL)
	setDepth(t[u].r,d+1);
}
int setHeight(int u){
	int h1=0,h2=0;
	if(t[u].l!=NIL)
	h1=setHeight(t[u].l)+1;
	if(t[u].r!=NIL)
	h2=setHeight(t[u].r)+1;
	return hei[u]=(h1>h2?h1:h2);
}
void print(int u){
	int sibling,degree=0;
	if(t[u].p==NIL)
	sibling=-1;
	else if(t[t[u].p].l==u)
	sibling=t[t[u].p].r;
	else if(t[t[u].p].r==u)
	sibling=t[t[u].p].l;
	if(t[u].l+1)
	degree++;
	if(t[u].r+1)
	degree++;
	printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, ",u,t[u].p,sibling,degree,dep[u],hei[u]);
	if(t[u].p==NIL)
	printf("root");
	else if(degree==0)
	printf("leaf");
	else
	printf("internal node");
	printf("\n");
}
int main(){
	int i,j,n;
	for(i=0;i<MAX;i++){
		t[i].p=NIL;
		t[i].l=NIL;
		t[i].r=NIL;
	}//初始化
	scanf("%d",&n);
	int id[n+1];
	for(i=0;i<n;i++){
		scanf("%d",&id[i]);
		scanf("%d%d",&t[id[i]].l,&t[id[i]].r);
		if(t[id[i]].l+1)
		t[t[id[i]].l].p=id[i];
		if(t[id[i]].r+1)
		t[t[id[i]].r].p=id[i];
	}//输入
	for(i=0;i<n;i++){
		if(t[i].p==NIL)
		break;
	}
	setHeight(i);
	setDepth(i,0);
	for(i=0;i<n;i++)
	print(i);//输出 
	return 0;
}
