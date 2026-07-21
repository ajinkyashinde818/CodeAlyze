#include <stdio.h>
#include <stdlib.h>

typedef struct _n {
  int deg;
  int right;
  int left;
  int r;
  int parent;
  int sib;
  int depth;
  int height;
} node;

//接点を格納する配列
node tree[100000];
int n;
//関数のプロトタイプ宣言
void setDepth(int);
int setHeight(int);
int main() {
  int i, j, k, l, r;
  //nを受け取る
  scanf("%d", &n);
  //木構造の各接点の情報を初期化
  for(i = 0; i < n; i++) {
    tree[i].parent = -1;
    tree[i].sib = -1;
    tree[i].depth = 0;
    tree[i].height = 0;
    tree[i].deg = 0;
  }
  //n行の入力を処理する（kでループしているがkは使わない）
  for(k = 0; k < n; k++) {
    //何番めの接点かをiに格納
    scanf("%d", &i);
    //接点の配列に、子を格納
    scanf("%d %d", &tree[i].left, &tree[i].right);
    //子の兄弟を設定
    if(tree[i].left != -1) tree[tree[i].left].sib = tree[i].right;
    if(tree[i].right != -1) tree[tree[i].right].sib = tree[i].left;
    //子に親を設定
    if(tree[i].left != -1)tree[tree[i].left].parent = i;
    if(tree[i].right != -1) tree[tree[i].right].parent = i;
    //子の数を設定
    if(tree[i].left != -1) tree[i].deg++;
    if(tree[i].right != -1) tree[i].deg++;
  }
  //kにrootとなる接点が配列の何番目にあるかを代入
  for(i = 0; i < n; i++) {
    if(tree[i].parent == -1) k = i;
  }
  //再帰関数を呼び出す（この関数で全てのtree[x].depthを設定）
  setDepth(k);
  //heightを設定する関数を呼び出す
  setHeight(k);
  //出力
  for(i = 0; i < n; i++) {
    //共通部分
    printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, ",
	   i, tree[i].parent, tree[i].sib, tree[i].deg, tree[i].depth, tree[i].height);
    
    //ここから接点の種類により分岐
    
    //接点の親が最初の-1から変わっていない場合それがrootとなる
    if(tree[i].parent == -1) {
      printf("root\n");
    }
    //子の数が0のときはleaf
    else if(tree[i].deg == 0) {
      printf("leaf\n");
    }
    /* leafでない場合internal nodeかrootになるが、
       rootの分岐は先に済ませたのでその他の場合　つまりinternal nodeの場合 
    */
    else {
      printf("internal node\n");
    }
  }
  return 0;
}

void setDepth(int r) {
  //引数は木構造のさくらんぼの繋がってる部分のイメージ（？）
  //tree[r]のそれぞれの子に、tree[r]の深さ+1をセット;
  if(tree[r].right != -1 )tree[tree[r].right].depth += 1 + tree[r].depth;
  if(tree[r].left != -1) tree[tree[r].left].depth += 1 + tree[r].depth;
  /* tree[r]のそれぞれの子から先の深さを決めるため、
     再帰的に関数を呼び出す
  */
  if(tree[r].left != -1) setDepth(tree[r].left);
  if(tree[r].right != -1) setDepth(tree[r].right);
}
int setHeight(int r) {
  int i, h=0, hl, hr, n;
  if(tree[r].deg == 0) {
    tree[r].height = 0;
    return 0;
  }
  if(tree[r].left != -1) hl = setHeight(tree[r].left);
  else hl = 0;
  if(tree[r].right != -1) hr = setHeight(tree[r].right);
  else hr = 0;
  h = (hl < hr)? hr: hl;
  h++;
  tree[r].height = h;
  return h;
}
