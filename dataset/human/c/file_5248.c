// Binary Trees
#include <stdio.h>
#define MAX 25 // 接点の個数の上限
#define NIL -1 // 接点番号として使われない値を設定(とりあえず-1としておく)

struct node{
  int parent; // 接点の親を参照
  int left;   // 左の子を参照
  int right;  // 右の子を参照
};
struct node T[MAX];

int getDegree(int);
int getDepth(int);
int getSibling(int);
int getHeight(int);
int printNodeType(int);

int main(){
  int i, n, id, l, r;

  scanf("%d", &n);

  for(i=0; i < n; i++){ // NILを代入して初期化
    T[i].parent = T[i].left = T[i].right = NIL;
  }

  for(i=0; i < n; i++){
    scanf("%d", &id);
    scanf("%d%d", &T[id].left, &T[id].right);
    T[T[id].left].parent = T[T[id].right].parent = id;
  }

  for(i=0; i < n; i++){
    printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, ",
    i, T[i].parent, getSibling(i), getDegree(i), getDepth(i), getHeight(i));
    printNodeType(i);
      printf("\n");
  }
  return 0;
}

// 接点の子の数を返す
int getDegree(int u){
  int count=0;
  if(T[u].left != NIL)count++;
  if(T[u].right != NIL)count++;
  return count;
}

// 接点の深さを返す
int getDepth(int u){
  int d=0;
  while(T[u].parent != NIL){
    u = T[u].parent;
    d++;
  }
  return d;
}

// 接点の兄弟を返す
int getSibling(int u){
  int p;
  p = u;
  if(T[u].parent == NIL) return -1;
  else u = T[u].parent;
  if(T[u].left != NIL && T[u].left != p) return T[u].left;
  else if(T[u].right != NIL && T[u].right != p) return T[u].right;
  else return -1;
}

// 接点の高さを返す
int getHeight(int u){
  int h1=0, h2=0;
  if(T[u].right != NIL)h1 = getHeight(T[u].right) + 1;
  if(T[u].left != NIL)h2 = getHeight(T[u].left) + 1;
  if(h1 > h2)return h1;
  else return h2;
}

// 根、内部ノードまたは葉のどれかを判定して表示
int printNodeType(int u){
  if(T[u].parent == NIL)printf("root");
  else if(T[u].left == NIL && T[u].right == NIL)printf("leaf");
  else printf("internal node");
}
