#include<stdio.h>
#define NIL -1
#define MAX 1000001
struct node{
	int p,l,r;
};
struct node t[MAX];
int deep[MAX];
int  getDepth(int u){
	int d=0;
	while(t[u].p!=NIL){
		u=t[u].p;
		d++;
	}
	return d;
}
void setDepth(int u,int d){
	deep[u]=d;
	if(t[u].r!=NIL)
	setDepth(t[u].r,d);
	if(t[u].l!=NIL)
	setDepth(t[u].l,d+1);
}
void printChildren(int u){
	int c=t[u].l;
	int time=0;
	printf(", [");
	while(c!=NIL){
		if(time)
		printf(", ");
		printf("%d",c);
		c=t[c].r;
		time++;
	}
	printf("]\n");
}
int main(){
    int n,i,j,k;
    scanf("%d",&n);
    for(i=0;i<n;i++){
    	t[i].l=NIL;
    	t[i].p=NIL;
    	t[i].r=NIL;
	}//初始化 
    int id[n];
    for(i=0;i<n;i++){
    	scanf("%d%d",&id[i],&k);
    	if(k){
    	int ch[k];
    	for(j=0;j<k;j++){
    		scanf("%d",&ch[j]);
            if(j)
            t[ch[j-1]].r=ch[j];
            t[ch[j]].p=id[i];
		}
		t[id[i]].l=ch[0];}
	}//输入 
    for(i=0;i<n;i++){
    	deep[i]=getDepth(i);
	}//求深度 
	for(i=0;i<n;i++){
		printf("node %d: parent = %d, depth = %d, ",i,t[i].p,deep[i]);
		if(deep[i]==0)
		printf("root");
		else if(t[i].l==NIL)
		printf("leaf");
		else
		printf("internal node");
		printChildren(i);
	}
	return 0;
}
