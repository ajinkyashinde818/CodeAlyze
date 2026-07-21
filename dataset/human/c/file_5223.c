#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int degree; /* 子の数 */
  int depth; /* 深さ */
  int height; /* 高さ */
  int parent; /* 親の値 */
  int sibling; /* 兄弟 */
  int left; /* 左側の子ノード */
  int right; /* 右側の子ノード */
} Node;

int cal_depth(Node *,int);
int cal_height(Node *,int);

Node T[30];

int main()
{
  int i,n,value = -1;
  scanf("%d",&n);

  /* 初期化 */
  for(i = 0;i < n;i++){
    T[i].depth = 0;
    T[i].height = 0;
    T[i].parent = -1;
    T[i].sibling = -1;
    T[i].left = -1;
    T[i].right = -1;
  }

  for(i = 0;i < n;i++){   
    scanf("%d",&value);
    scanf("%d",&T[value].left);
    scanf("%d",&T[value].right);
    if(T[value].left != -1){
      T[value].degree ++;
      T[T[value].left].sibling = T[value].right;   /* 存在したら、兄弟を入力する */
    }
    if(T[value].right != -1){
      T[value].degree ++;
      T[T[value].right].sibling = T[value].left;  /* 存在したら、兄弟を入力する */
    }
    T[T[value].left].parent = value;   /* 親を入力 */
    T[T[value].right].parent = value;
  }
  
  for(i = 0;i < n;i++){   /* ツリーを作ってから、高さと深さの計算をする */
    T[i].depth = cal_depth(T,i);
    T[i].height = cal_height(T,i);
  }
  

  /* 出力 */
  for(i = 0;i < n;i++){
    printf("node %d: parent = %d, sibling = %d, ",i,T[i].parent,T[i].sibling);     
    printf("degree = %d, depth = %d, height = %d, ",T[i].degree,T[i].depth,T[i].height);
    if(T[i].parent == -1) printf("root\n");
    else if((T[i].left == -1) && (T[i].right == -1)) printf("leaf\n");
    else printf("internal node\n");
  }

  return 0;
}

    
int cal_depth(Node *T,int now) /* 深さの計算 */
{ 
  if(T[now].parent != -1) return cal_depth(T,T[now].parent) + 1;
  return 0;
}

int cal_height(Node *T,int now) /* 高さの計算 */
{
  int sum_right = 0,sum_left = 0;

  if(T[now].left != -1) sum_left = cal_height(T,T[now].left) +1;
  if(T[now].right != -1) sum_right = cal_height(T,T[now].right) +1;

  if(sum_right >= sum_left) return sum_right;  /* 左と右の両方のパターンを計算し、大きいほうを返す */
  else return sum_left;
}
