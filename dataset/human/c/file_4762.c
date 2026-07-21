/* 二分木　*/
#include <stdio.h>

#define MAX 25       /*　最大ノード数　*/
#define NIL -1

typedef struct{

  int left;          /*　左の子ども　*/
  int right;         /*　右の子ども　*/
  int parent;        /*　親　*/  
}Node;

Node T[MAX];         /*　二分木　*/
int n;               /* ノード数　*/
int depth[MAX];      /* 各ノードの深さ　*/
int height[MAX];     /* 各ノードの高さ　*/
int degree[MAX];     /* 各ノードの子の数　*/

/*　関数プロトタイプ宣言　*/
void GetDepth(int, int);
int  GetHeight(int);
void print(int);

int main()
{
  int i, j, d, v, c, l, root;

  scanf("%d", &n);

  /*　二分木をNILで初期化　*/
  for( i = 0; i<n; i++ )
    T[i].left = T[i].right = T[i].parent = NIL;
  
  /* 二分木の各ノードの情報を読み込み　*/
  for( i = 0; i<n; i++ )
    {
      scanf("%d", &v);
      scanf("%d%d", &T[v].left, &T[v].right);

      /*　子どもの数を設定　*/
      if( T[v].left != NIL && T[v].right != NIL )
	degree[v] = 2;
      else if( T[v].left == NIL && T[v].right == NIL )
	degree[v] = 0;
      else
	degree[v] = 1;
      
      /*　左の子、右の子それぞれに親の番号を設定　*/
      if( T[v].left != NIL )
	T[ T[v].left ].parent = v;
      if( T[v].right != NIL )
	T[ T[v].right ].parent = v;
    }

  /* ルートノードを求める　*/
  for( i = 0; i<n; i++ )
    {
      if( T[i].parent == NIL )
        {
          root = i;
          break;
        }
    }

  /*　各ノードの深さを求める　*/
  GetDepth(root, 0);

  /*　各ノードの高さを求める　*/
  GetHeight(root);

  /*　根付きノードの情報を表示*/
  for( i = 0; i<n; i++ )
    print(i);
  
  return 0;
}

/*　各ノードの深さを再帰的に求める関数　
    引数：　u -> その時着目しているノードの番号　　p ->　その時着目しているノードの深さ　*/
void GetDepth(int u, int p)
{
  if( u == NIL )
    return;
  depth[u] = p;

  GetDepth(T[u].left, p+1);         /*　左の子の深さを求める　*/
  GetDepth(T[u].right, p+1);        /*　右の子の深さを求める　*/
}


/*  各ノードの高さを再帰的に求める関数　
    引数：　u -> その時着目しているノードの番号      戻り値：その時着目しているノードの高さ　*/
int GetHeight(int u)
{
  int h1 = 0, h2 = 0;

  if( T[u].left != NIL )
    h1 = GetHeight(T[u].left) + 1;        /*　左の子の高さを求める　*/
  if( T[u].right != NIL )
    h2 = GetHeight(T[u].right) + 1;       /*　右の子の高さを求める　*/

  return height[u] = ( h1 > h2 ? h1 : h2);
}


/*　ノードT[u]の情報を出力する関数　*/
void print(int u)
{
  int c;

  /* node, parentを表示　*/
  printf("node %d: parent = %d, ", u, T[u].parent);

  /* 兄弟の番号を表示　*/
  if( T[u].parent == NIL )
    printf("sibling = %d, ", NIL);
  else if( T[ T[u].parent ].left == u )
    printf("sibling = %d, ", T[ T[u].parent ].right);
  else
    printf("sibling = %d, ", T[ T[u].parent ].left);

  /*　子の数、深さ、高さを表示　*/
  printf("degree = %d, depth = %d, height = %d, ", degree[u], depth[u], height[u]);

  /* ノードのタイプを表示　*/
  if( T[u].parent == NIL )
    printf("root\n");
  else if( T[u].left == NIL && T[u].right == NIL )
    printf("leaf\n");
  else
    printf("internal node\n");
}
