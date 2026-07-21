#include<stdio.h>
#define MAX 100005
#define	NIL -1

struct Node{ 
	int p,l,r;
};

struct Node T[MAX]; 

int depth(int x){
	if(T[x].p == NIL){
		return 0;
	} else {
		return 1+depth(T[x].p);
	}
}

int degree(int x){
	if(T[x].l != NIL && T[x].r != NIL){
		return 2;
	}else if(T[x].l != NIL || T[x].r != NIL){
		return 1;
	}else{
		return 0;
	}
}

int sibling(int p,int x){
	if(p == NIL){
		return NIL;
	} else if(T[p].l == x){
		return T[p].r;
	} else {
		return T[p].l;
	}
}

int height(int x){
	int l_h = 0, r_h = 0;

	if(x == NIL){
		return 0;
	}

	if(T[x].l != NIL){
		l_h = height(T[x].l)+1;
	}
	if(T[x].r != NIL){
		r_h = height(T[x].r)+1;
	}

	if(l_h > r_h){
		return l_h;
	}else{
		return r_h;
	}
}


void print(int u){
	printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, " ,u ,T[u].p ,sibling(T[u].p,u) ,degree(u) ,depth(u) ,height(u));

	if(T[u].p == NIL){
		printf("root\n");
	}else if(T[u].l == NIL && T[u].r == NIL){
		printf("leaf\n");
	}else{
		printf("internal node\n");
	}
}

int main(){
	int n,i,id,right,left;

	scanf("%d",&n);

	for(i = 0; i < n; i++){
		T[i].p = NIL;
		T[i].l = NIL;
		T[i].r = NIL;
	}

	for(i = 0; i < n; i++){
		scanf("%d%d%d",&id ,&right ,&left);

		T[right].p = id;
		T[left].p = id;
		T[id].l = right;
		T[id].r = left;
	}

	for(i=0; i<n; i++){
		print(i);
	}
	return 0;
}
