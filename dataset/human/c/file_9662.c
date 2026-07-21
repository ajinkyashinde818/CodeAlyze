// 与えられた根付き木 T の各節点 u について、以下の情報を出力するプログラムを作成してください。
// - u の節点番号
// - u の親の節点番号
// - u の深さ
// - u の節点の種類（根、内部節点または葉）
// - u の子のリスト
// ここでは、与えられる木は n 個の節点を持ち、それぞれ 0 から n−1 の番号が割り当てられているものとします。 

#include<stdio.h>
#include<stdlib.h>

#define MAX 100005
#define NIL -1

struct Node{
  int parent;
  int degree;   
  int *children;
  int depth; // D is the depth
};

struct Node T[MAX];
int n, H;

// Find the depth of a given node by tracking back to the parents until the root
int getDepth(int u){
  int d = 0;

  for(; T[u].parent != NIL ;d++) u = T[u].parent;

  return d;
}

// Print the information for a given node
void print(int u){
  int i, c;

  printf("node %d: ", u);
  printf("parent = %d, ", T[u].parent);
  printf("depth = %d, ", T[u].depth);

  if ( T[u].parent == NIL ) printf("root, ");
  else if ( T[u].degree == 0 ) printf("leaf, ");
  else printf("internal node, ");

  printf("[");
  for(i = 0; i< T[u].degree; i++){
    if (i) printf(", ");
    printf("%d", T[u].children[i]);
  }
  printf("]\n");
}

int main(){
  int i, j, d, v, c, l;

// Reset all nodes
  scanf("%d", &n);
  for ( i = 0; i < n; i++ ){
    T[i].parent = NIL;
    T[i].degree=0;
  }

// Build the tree based on the input data
  for ( i = 0; i < n; i++ ){
    scanf("%d %d", &v, &d); // v and d are the ID and degree of the node
    T[v].degree=d;
    if(d==0) continue;

    T[v].children=(int *)malloc(d*sizeof(int));
    for ( j = 0; j < d; j++ ){
      scanf("%d", &c);
      T[v].children[j]=c;
      T[c].parent = v;
    }
  }
  
  H = 0;
  for ( i = 0; i < n; i++ ){
    T[i].depth = getDepth(i);
    if ( T[i].depth > H ) H = T[i].depth;
  }

// Print the tree
  for ( i = 0; i < n; i++ ) print(i);
  return 0;
}
