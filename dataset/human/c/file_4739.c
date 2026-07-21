#include<stdio.h>


typedef struct{
	int v;
	int l,r;
}node;

int check(int a[],int n){
	int i;
	for(i=0;i<n;i++){
		if(a[i]==0)return 0;
	}
	return 1;
} 

void searchRoot(int v[],int id,node t[]){
	if(id==-1)return;
	v[id]=1;
	searchRoot(v,t[id].l,t);
	searchRoot(v,t[id].r,t);
}

void search(int key,int id,node t[],int p,int s,int d){
	if(id==-1)return;
	if(key==id){
		int count=0;
		if(t[key].l!=-1)count++;
		if(t[key].r!=-1)count++;
		printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, ",key,p,s,count,d);
		return;
	}
	search(key,t[id].l,t,id,t[id].r,d+1);
	search(key,t[id].r,t,id,t[id].l,d+1);
}

int max(int a,int b){
	if(a>b)return a;
	return b;
}

int searchH(int key,node t[]){
	if(key==-1)return -1;
	return max(searchH(t[key].l,t),searchH(t[key].r,t))+1;
}


int main(void){
	node tree[26];
	int visit[26];
	int n,id,l,r;
	int i;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d %d %d",&id,&l,&r);
		tree[id].l=l;
		tree[id].r=r;
		visit[id]=0;
	}
	int root;
	for(i=0;i<n;i++){
		searchRoot(visit,i,tree);
		if(check(visit,n)==1){
			root=i;
			break;
		}
	}
	int maxH;
	for(i=0;i<n;i++){
		search(i,root,tree,-1,-1,0);
		printf("height = %d, ",searchH(i,tree));
		if(root==i)printf("root");
		else if(tree[i].r==-1&&tree[i].l==-1)printf("leaf");
		else printf("internal node");
		printf("\n");
	}
	
	return 0;
}
