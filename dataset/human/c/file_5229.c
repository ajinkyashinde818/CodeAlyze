#include<stdio.h>
#define Max 10000
#define Oya -1

int setHeight(int);
void setDepth(int,int);
void print(int);
int getSibling(int);

typedef struct{
  int parent,left,right;
}Node;

Node T[Max];
int n, D[Max], H[Max];

void setDepth(int u, int d){
  if(u == Oya) return;
  D[u] = d;
  setDepth(T[u].left, d+1);
  setDepth(T[u].right, d+1);
}

int setHeight(int u){
  int h1 =0,h2=0;
  if(T[u].left != Oya){
    h1 = setHeight(T[u].left)+1;}
  if(T[u].right != Oya){
    h2 = setHeight(T[u].right)+1;}
  if(h1>h2){
    H[u] = h1;
    return H[u];}
  else{
    H[u] = h2;
    return H[u];}
}

int main(){

  int K,i,left,right,n,root=0;
    scanf("%d",&n);

    for(i = 0; i<n; i++){
      T[i].parent = Oya;
    }

    for(i=0; i<n; i++){
      scanf("%d %d %d", &K,&left,&right);
      T[K].left = left;
      T[K].right = right;
      if(left != Oya) T[left].parent = K;
      if(right != Oya) T[right].parent = K;
    }

    for(i=0; i<n; i++){
      if(T[i].parent == Oya) root = i;
    }

    setDepth(root,0);
    setHeight(root);

    for(i=0; i<n; i++) print(i);

    return 0;
	  
}

void print(int u){
  printf("node %d: ",u);
  printf("parent = %d, ", T[u].parent);
  printf("sibling = %d, ", getSibling(u));
  int deg = 0;
  if(T[u].left != Oya) deg++;
  if(T[u].right != Oya) deg++;
  printf("degree = %d, ",deg);
  printf("depth = %d, ",D[u]);
  printf("height = %d, ",H[u]);

  if(T[u].parent == Oya){
    printf("root\n");
  }
  else if(T[u].left == Oya && T[u].right == Oya){
    printf("leaf\n");
  }
  else{
    printf("internal node\n");
  }
}

int getSibling(int u){
  if(T[u].parent == Oya) return Oya;
  if(T[T[u].parent].left != u && T[T[u].parent].left != Oya)
    return T[T[u].parent].left;
  if(T[T[u].parent].right != u && T[T[u].parent].right != Oya)
    return T[T[u].parent].right;
  return Oya;
}
