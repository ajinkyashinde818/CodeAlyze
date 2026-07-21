#include <stdio.h>

typedef struct{int p,l,r;}Node;

int getD(int);
int getH(int);
int getS(int);
void print(int);

Node T[10000];
int H[10000],n;

int main(){
	int i,v,left,right,root=0;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		T[i].p=-1;
	}
	for(i=0;i<n;i++){
		scanf("%d%d%d",&v,&left,&right);
		T[v].l=left;
		T[v].r=right;
		if(left != -1)T[left].p=v;
		if(right != -1)T[right].p=v;
	}
	for(i=0;i<n;i++){
		if(T[i].p == -1) root = i;
	}

	getH(root);
	for(i=0;i<n;i++){
		print(i);
	}
  return 0;
}

int getD(int u){
  int d=0;
  while(T[u].p != -1){
    u = T[u].p;
    d++;
  }
  return d;
}

int getH(int u){
  int h1 = 0,h2 = 0;
  if(T[u].l != -1){
    h1 = getH(T[u].l)+1;
  }
  if(T[u].r != -1){
    h2 = getH(T[u].r)+1;
  }
  if(h1>h2) return H[u] = h1;
  else return H[u] = h2;
}

int getS(int u){
  if(T[u].p == -1)return -1;
  if(T[T[u].p].l != u && T[T[u].p].l != -1)
    return T[T[u].p].l;
  if(T[T[u].p].r != u && T[T[u].p].r != -1)
    return T[T[u].p].r;
  return -1;
}

void print(int u){
  int i;
  printf("node %d: ",u);
  printf("parent = %d, ",T[u].p);
  printf("sibling = %d, ",getS(u));
  int deg = 0;
  if(T[u].l != -1) deg++;
  if(T[u].r != -1) deg++;
  printf("degree = %d, ",deg);
  printf("depth = %d, ",getD(u));
  printf("height = %d, ",H[u]);
  if(T[u].p == -1){
  	printf("root\n");
  }
  else if(T[u].l == -1 && T[u].r == -1){
  	printf("leaf\n");
  }
  else
  	printf("internal node\n");
}
