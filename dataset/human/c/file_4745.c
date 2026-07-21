#include <stdio.h>
#define N 100000

typedef struct{
  int p,r,l;
}Node;

Node T[N];
int n,D[N],H[N];

int depth(int);
int degree(int);
int hight(int);
int subiling(int);
void print(int);

int main()
{
int i,j,p,l,r,n;
	scanf("%d", &n);
	for(i=0; i<n; i++){
		T[i].p = -1;
		T[i].l = -1;
		T[i].r = -1;
	}
	for(i=0; i<n; i++){
		scanf("%d%d%d",&p,&l,&r);
		T[l].p = p;
		T[r].p = p;
		T[p].l = l;
		T[p].r = r;
	}
	for(i=0; i<n; i++){
		print(i);
	}
	return 0;
}
   
int depth(int c){
  int cnt = 0;
  if(T[c].p == -1){
    return 0;
  }
  else{
    cnt = depth(T[c].p) + 1;
    return cnt;
  }
}

int degree(int x){
  if(T[x].l ==-1 && T[x].r == -1){
    return 0;
  }
  else if(T[x].l !=-1 && T[x].r != -1){
    return 2;
  }
  else
    return 1;
}

int hight(int s){
	int h1 = 0, h2 = 0;
	if(T[s].l != -1){
		h1 = hight(T[s].l ) + 1;
	}
	if(T[s].r != -1){
		h2 = hight(T[s].r) + 1;
	}
 
	if(h1 < h2)return H[s] = h2;
	else return H[s] = h1;
}
 
int sibiling(int s){
	if(T[s].p == -1)return -1;
	if(T[T[s].p].l != -1 && T[T[s].p].l != s ){
		return T[T[s].p].l;
	}
	if(T[T[s].p].r != -1 && T[T[s].p].r != s ){
		return T[T[s].p].r;
	}
	return -1;
}

void print(int f){
	printf("node %d: parent = %d, sibling = %d, degree = %d, ",f, T[f].p, sibiling(f),degree(f));
	printf("depth = %d, height = %d, ",depth(f),hight(f));
	if(T[f].p == -1){
		printf("root\n");
	}
	else if(T[f].l == -1 && T[f].r == -1){
		printf("leaf\n");
	}
	else{
		printf("internal node\n");
	}
}
