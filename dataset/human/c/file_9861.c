#include<stdio.h>
#include<string.h>
#define MAX 100000
#define LEN 14
#define NIL -1

typedef struct{
  int parent;
  int left; //自分の子供かつ一番左のやつ
  int right; //すぐ右隣の兄弟
  char state[LEN]; //節点の種類
  int depth; //深さ
}node;

void setDepth(int, int);
void printChildren(int);

node t[MAX];

int main(){
  int n, k, c[MAX], index, root; //kは子供の数, cは子供の節点番号, indexは節点番号
  int i, j;

  scanf("%d", &n);

  //初期化
  for(i=0;i<n;i++){
    t[i].parent = t[i].left = t[i].right = NIL;
  }
  
  for(i=0;i<n;i++){
    scanf("%d", &index);

    scanf("%d", &k);
    if(k == 0) c[0] = NIL; //子供いないなら一番左の子をNILに
    for(j=0;j<k;j++){
      scanf("%d", &c[j]);
    }
    

    for(j=0;j<k;j++){
      /*
      if(j == k-1) printf("%d\n", c[j]);
      else printf("%d ", c[j]);
      */
      t[c[j]].parent = index; //親の設定
      if(j != k-1) t[c[j]].right = c[j+1]; //一番右の子じゃないならすぐ右隣の兄弟設定。c[k-1]が最右
    }

    t[index].left = c[0]; //一番左の子はc[0]
  }

  /*
  for(i=0;i<n;i++){
    printf("%2d: parent %2d: left %2d: right %2d\n", i, t[i].parent, t[i].left, t[i].right);
  }
  */
  for(i=0;i<n;i++){
    if(t[i].parent == NIL) root = i;
  }

  setDepth(root, 0);
  
  for(i=0;i<n;i++){
    if(t[i].parent == NIL) strcpy(t[i].state, "root"); //親がいないnodeがroot
    else if(t[i].left == NIL) strcpy(t[i].state, "leaf"); //左の子がいないnodeがleaf
    else strcpy(t[i].state, "internal node"); //それ以外中間node
    printf("node %d: parent = %d, depth = %d, %s, ", i, t[i].parent, t[i].depth, t[i].state);
    printChildren(i);
  }
  
  return 0;
}

//uは節点番号, dはuの深さ
void setDepth(int u, int d){
  t[u].depth = d;
  if(t[u].right != NIL) setDepth(t[u].right, d); //節点uが一番右じゃないとき、節点右にずらして深さそのまま
  if(t[u].left != NIL) setDepth(t[u].left, d+1); //節点uに子がいるとき、深さ1つ更新して下に
}

void printChildren(int u){
  int c; 
  c = t[u].left; //最初に一番左の子をcに設定

  printf("[");
  //子がいる間
  while(c != NIL){
    printf("%d", c);
    if(t[c].right != NIL) printf(", ");
    c = t[c].right;
  }
  printf("]\n");
}
