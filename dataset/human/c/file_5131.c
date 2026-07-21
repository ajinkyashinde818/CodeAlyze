#include<stdio.h>
 
#define MAX 100000
 
struct Node {
  int p,l,r;
};
 
struct Node T[MAX];
int D[MAX],H[MAX]; 

int Sibling(int);
void Depth(int,int);
int Height(int);
void print(int);

int main()
{
  int i,n,left,right,id,root = 0;
 
  scanf("%d",&n);
 
  for(i = 0; i < n ;i++){
    T[i].p = -1;
  }
 
  for(i = 0; i < n; i++){ 
    scanf("%d%d%d",&id,&left,&right);
 	T[id].l = left;
 	T[id].r = right;
 	if(left != -1) T[left].p = id;
 	if(right != -1) T[right].p = id;
  }
 
 for(i = 0; i < n; i++){
 	if(T[i].p == -1) root = i;
 }
 
 Depth(root, 0);
 Height(root);
 
 for(i = 0; i < n; i++){
 	print(i);
 }
  
  return 0;
}
 
int Sibling(int i){
 	if(T[i].p == -1) return -1;
 	else if(T[T[i].p].l != i && T[T[i].p].l != -1) return T[T[i].p].l;
 	else if(T[T[i].p].r != i && T[T[i].p].r != -1) return T[T[i].p].r;
 	else return -1;
 }
 
void Depth(int root,int x){
	if(root == -1) return;
	D[root] = x;
	Depth(T[root].l,x+1);
	Depth(T[root].r,x+1);
}

int Height(int root){
	int h1 = 0;
	int h2 = 0;
	if(T[root].l != -1) h1 = Height(T[root].l) + 1;
	if(T[root].r != -1) h2 = Height(T[root].r) + 1;
	
	if(h1 > h2){
	H[root] = h1;
	return h1;
	}
	else {
	H[root] = h2;
	return h2;
	}
}

void print(int i){
	int count = 0;
	
	printf("node %d: parent = %d, sibling = %d, ",i,T[i].p,Sibling(i));
	
	if(T[i].l != -1) count++;
	if(T[i].r != -1) count++;
	
	printf("degree = %d, depth = %d, height = %d, ",count,D[i],H[i]);
	
	if(T[i].p == -1) printf("root\n");
    else if(T[i].l == -1 && T[i].r == -1) printf("leaf\n");
    else printf("internal node\n");
}
