#include <stdio.h>
#define MAX 100000

typedef struct{
  int parent;
  int left;
  int right;
  int depth;
  int height;
}Node;

Node T[MAX];
int c[2];

int getDepth(int);
int getHeight(int);
void print(int);

int main(){
  int l, n, m, i, j, k;

  scanf("%d", &n);
  
  for(i = 0; i < n; i++){
    T[i].parent = -1;
    T[i].left = -1;
    T[i].right = -1;
  }
  
  for(i = 0; i < n; i++){
    scanf("%d", &l);
    for(j = 0; j < 2; j++){
      scanf("%d", &c[j]);
      if(c[j] != -1){
	T[c[j]].parent = l;
	if(j == 0) T[l].left = c[j];
	else T[l].right = c[j];
      }
    }
  }

  for(i = 0; i < n; i++){
    T[i].depth = getDepth(i);
    T[i].height = getHeight(i);
  }

  print(n);
  
  return 0;
}

void print(int n){
  int m, i, j;
  
  for(i = 0; i < n; i++){
    printf("node %d: parent = %d, sibling = ", i, T[i].parent);

    if(T[i].parent == -1) printf("-1, ");
    else if(T[T[i].parent].left == i && T[T[i].parent].right == -1) printf("-1, ");
    else if(T[T[i].parent].right == i && T[T[i].parent].left == -1) printf("-1, ");
    else if(T[T[i].parent].left == i) printf("%d, ", T[T[i].parent].right);
    else if(T[T[i].parent].right == i) printf("%d, ", T[T[i].parent].left);
    
    printf(T[i].left == -1 && T[i].right == -1 ? "degree = 0, " :
	   T[i].left != -1 && T[i].right != -1 ? "degree = 2, " : "degree = 1, ");
    
    printf("depth = %d, ", T[i].depth);
    printf("height = %d, ", T[i].height);
    
    printf(T[i].parent == -1 ? "root" :
	   T[i].left == -1 && T[i].right == -1 ? "leaf" : "internal node");
    printf("\n");
  }
}

int getDepth(int u){
  if(T[u].parent == -1) return 0;
  return getDepth(T[u].parent) + 1;
}

int getHeight(int u){
  int a = 0, b = 0;
  if(T[u].left != -1) a = getHeight(T[u].left) + 1;
  if(T[u].right != -1) b = getHeight(T[u].right) + 1;
  return a>b ? a : b;
}
