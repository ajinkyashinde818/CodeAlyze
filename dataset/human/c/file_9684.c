/*自由木を作成し、それらの情報を書き出すプログラム*/
#include<stdio.h>

/*マクロ*/
#define MAX 100005
#define NIL -1

/*グローバル変数*/
int n, D[MAX];//n=接点の個数
int dep = 0;

/*プロトタイプ宣言*/
void TreePrint(int );

/*構造体(入れ子)*/
struct Node{ 
  int p, l, r;
};

struct Node T[MAX];



int main(){
  int i, j;//カウンター変数
  int d, v, c, l;//d=degree, v=verteck, c=child, l=leaf`
  int u = 0;
  int dep = 0;

  scanf("%d", &n);

  for(i = 0; i < n; i++) {
    T[i].p = NIL;
    T[i].l = NIL;
    T[i].r = NIL;
  }
  
  for(i = 0; i < n; i++) {
    scanf("%d %d", &v, &d);

    for(j = 0; j < d; j++) {
      scanf("%d", &c);

      T[c].p = v;

      if(j == 0) {
	T[v].l = c;
      }

      if(j > 0) {
	T[l].r = c;
      }
	l = c;
    }

  }


  for(i = 0 ;i < n ;i++) {
    u = i;

  while(1)
    {
    if(T[u].p == NIL)  {
      break;
    }
    // printf("%d\n",dep);
    dep++;
    u = T[u].p;
    }

    D[i] = dep;
    dep = 0;
  }
  
  for(i = 0 ;i < n ;i++) {

    TreePrint(i);
  }
 
  return 0;
}

/*結果を出力する関数*/
void TreePrint(int u) {
  int i;

  printf("node %d: parent = %d, depth = %d, ",u ,T[u].p ,D[u]);

  if(T[u].p == NIL) {
    printf("root, ");
  }

  else if(T[u].l == NIL) {
    printf("leaf, ");
  }

  else if(T[u].l != NIL) {
    printf("internal node, ");
  }

  printf("[");

  if(T[u].l != NIL) {
    printf("%d",T[u].l);
    u=T[u].l;
  

    if(T[u].r != NIL)printf(", ");

    while(1){
	if(T[u].r == NIL)break;

      printf("%d",T[u].r);
      u=T[u].r;

      if(T[u].r != NIL) {
	printf(", ");
      }

    }
  }
  
  printf("]\n");
}
