#include<stdio.h>
#define Max 1000000
#define Oya -1


void setDepth(int,int);
void print(int);

typedef struct{
  int parent,left,right;
}Node;

Node T[Max];
int n, D[Max], H[Max];

void setDepth(int u, int d){
  D[u] = d;

  if(T[u].right != Oya)
    setDepth(T[u].right, d);
  if(T[u].left != Oya)
    setDepth(T[u].left, d+1);
}

int main(){

  int i,j,d,v,c,left,right,root;
    scanf("%d",&n);

    for(i = 0; i<n; i++){
      T[i].parent = T[i].left = T[i].right = Oya;
    }
    
    for(i=0; i<n; i++){
      scanf("%d %d",&v,&d);
      for(j=0; j<d; j++){
	scanf("%d",&c);
	if(j==0)
	  T[v].left = c;
	else
	  T[left].right = c;
	left = c;
	T[c].parent = v;
      }
    }

    for(i=0; i<n; i++){
      if(T[i].parent == Oya) root = i;
    }

    setDepth(root,0);
   

    for(i=0; i<n; i++) print(i);

    return 0;
}

void print(int u){
  int i,c;

  printf("node %d: ",u);
  printf("parent = %d, ", T[u].parent);
  printf("depth = %d, ",D[u]);

  if(T[u].parent == Oya){
    printf("root, ");
  }
  else if(T[u].left == Oya){
    printf("leaf, ");
  }
  else{
    printf("internal node, ");
  }

  printf("[");

  for(i=0, c=T[u].left; c!=Oya; i++,c=T[c].right){
    if(i)
      printf(", ");
    printf("%d",c);
}

  printf("]\n");
}
