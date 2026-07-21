#include<stdio.h>

int depth(int node,int d[]){
	return d[node];
}
void search(int i, int depth,int d[], int mark[], int b[]){
	d[i] = depth;
	int index = mark[i];
	int count = b[index]; // nuber of children
	for(int j = 0; j < count; j++){
		search(b[index+1+j],depth+1,d,mark,b);
	}
}
void pre_process(int d[], int n,int a[],int mark[],int b[]){
	int parent;
	for(int i = 0; i<n; i++){
		if(a[i] == -1){
			parent = i; break;
		}
	}
	//printf("%d\n",parent);
	d[parent] = 0;
	search(parent,0,d,mark,b);
}
void check_type(int a[],int type[], int node,int n){
	int tag = 0;//0: leaf, 1: internal
	if(a[node]==-1) printf("root, ");
	else{
		if(type[node]==2)printf("internal node, ");
		else printf("leaf, ");
	}	
}

void check_children(int b[], int mark[], int node,int n){
	int index = mark[node]; //
	int count = b[index]; //how many children
	printf("[");
	for(int i = 0; i<count-1; i++){
		printf("%d, ",b[index+i+1]);
	}
	if(count!=0)
	printf("%d]",b[index+count]);
	else printf("]");
}
int main(){
	int n;
	scanf("%d",&n);
	int a[n];
	int b[200001];
	int d[n];
	int type[n];
	for(int i = 0; i<n; i++){
		a[i] = -1;
		d[i] = -1;
		type[i] = 2; // 0: root, 1: leaf, 2: internal
	}
	int index = 0;
	int mark[n];
	for(int i = 0; i<n; i++){
		int parent;
		scanf("%d",&parent);
		int k;
		scanf("%d",&k); //unmber of children
		if(k==0) type[parent] = 1;//leaf
		mark[parent] = index;
		b[index++] = k;
		int child;
		for(int j = 0; j<k; j++){
			scanf("%d",&child);
			b[index++] = child;
			a[child] = parent;
		}
	}
	pre_process(d, n,a,mark,b);
	//print
	for(int i = 0; i<n; i++){
		printf("node %d: parent = %d, depth = %d, ",i,a[i],depth(i,d));
		check_type(a,type,i,n);
		check_children(b,mark,i,n);
		printf("\n");	
	}
	return 0;
}
