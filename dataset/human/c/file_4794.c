#include<stdio.h>
#include<string.h>
#define MAX 25
#define LEN 14
#define NIL -1

typedef struct{
  int parent;
  int left; //左の子の節点番号
  int right; //右の子の節点番号
  char state[LEN]; //節点の種類
  int depth; //深さ
  int sib; //兄弟
  int deg; //子の数
  int height; //高さ
}node;

void setDepth(int, int);
int setHeight(int, int);

node t[MAX];

int main(){
  int n, index, parent, root;
  int i;

  scanf("%d", &n);

  //初期化
  for(i=0;i<n;i++){
    t[i].parent = NIL;
    t[i].deg = 0;
  }
  
  for(i=0;i<n;i++){
    scanf("%d", &index);
    scanf("%d %d", &t[index].left, &t[index].right);
    //右の子と左の子の親を設定
    if(t[index].left != NIL) t[t[index].left].parent = index; 
    if(t[index].right != NIL) t[t[index].right].parent = index;
  }

  for(i=0;i<n;i++){
    if(t[i].parent == NIL) root = i;
  }

  setDepth(root, 0);
  setHeight(root, 0);

  for(i=0;i<n;i++){
    //stateの設定
    if(t[i].parent == NIL) strcpy(t[i].state, "root");
    else if(t[i].left == NIL && t[i].right == NIL) strcpy(t[i].state, "leaf");
    else strcpy(t[i].state, "internal node");

    //兄弟の設定
    //親がいる前提
    if(t[i].parent != NIL){
      parent = t[i].parent;
      //左に子がいてかつ自分が左の子ではないとき
      if(t[parent].left != NIL && t[parent].left != i) t[i].sib = t[parent].left;
      //右に子がいてかつ自分が右の子ではないとき
      else if(t[parent].right != NIL && t[parent].right != i) t[i].sib = t[parent].right;
      else t[i].sib = NIL;
    }
    else t[i].sib = NIL;

    //子の数の設定
    if(t[i].left != NIL) t[i].deg++;
    if(t[i].right != NIL) t[i].deg++;

    //printf("%2d: parent %2d: left %2d: right %2d\n", i, t[i].parent, t[i].left, t[i].right);
    //表示
    printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, %s\n",
	   i, t[i].parent, t[i].sib, t[i].deg, t[i].depth, t[i].height, t[i].state);
  }
  
  return 0;
}

//uは節点番号, dは深さ
void setDepth(int u, int d){
  t[u].depth = d;
  //子がいるとき深さ更新して再帰
  if(t[u].left != NIL) setDepth(t[u].left, d+1);
  if(t[u].right != NIL) setDepth(t[u].right, d+1);
}

//uは節点番号, hは高さ
int setHeight(int u, int h){
  int h1 = 0, h2 = 0;
  int ans;
  if(t[u].left != NIL) h1 = setHeight(t[u].left, h) + 1;
  if(t[u].right != NIL) h2 = setHeight(t[u].right, h) +1;
  if(h1 > h2) ans = h1;
  else ans = h2;
  t[u].height = ans;
  return ans;
}
