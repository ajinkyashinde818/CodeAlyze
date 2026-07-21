#include<stdio.h>
#define NIL -1
void setDepth(int ,int );
int setHeight(int );
int getSibling(int );

typedef struct{
  int p,l,r;/* 親、左、右 */
}Node;

Node T[10000];
int n,D[10000],H[10000]; /* D：深さ、H：高さ*/

int main()
{
  int i,v,l,r;
  int root=0;
  int degree;
  
  scanf("%d",&n);

  for(i=0;i<n;i++){
    T[i].p = NIL;
  }

  for(i=0;i<n;i++){
    scanf("%d%d%d",&v,&l,&r);
    T[v].l=l;
    T[v].r=r;
    if(l!=NIL) T[l].p = v;
    if(r!=NIL) T[r].p = v;
  }

  for(i=0;i<n;i++){
    if(T[i].p == NIL) root = i;
  }
  setDepth(root,0);
  setHeight(root);

  for(i=0;i<n;i++){
    printf("node %d: ",i); /* 節点番号 */ 
    printf("parent = %d, ",T[i].p); /* 親 */ 
    printf("sibling = %d, ",getSibling(i)); /* 兄弟 */

    degree = 0; // 子を０に初期化
    if(T[i].l != NIL) degree++; //左がいたら子としてカウント
    if(T[i].r != NIL) degree++; //右がいたら子としてカウント
    printf("degree = %d, ",degree);/* 子の数  */
    
    printf("depth = %d, ",D[i]); /* 深さ */ 
    printf("height = %d, ",H[i]); /* 高さ */

    if(T[i].p == NIL) printf("root\n");
    else if(T[i].l == NIL && T[i].r == NIL) printf("leaf\n");
    else printf("internal node\n");
  }
  return 0;
}

/* 深さ調べ */ 
void setDepth(int u,int p){
  if(u == NIL) return;
 D[u]=p;
 setDepth(T[u].l,p+1);
 setDepth(T[u].r,p+1);
}

/* 高さ調べ */
int setHeight(int u){
  int h1=0,h2=0;
  if(T[u].l != NIL) h1 = setHeight(T[u].l)+1;
   if(T[u].r != NIL) h2 = setHeight(T[u].r)+1;
   if(h1>h2) H[u] = h1;
   else H[u] = h2;
   return H[u];
}

/* 兄弟調べ */
int getSibling(int u){
  if(T[u].p == NIL) return NIL;
  if(T[T[u].p].l != u && T[T[u].p].l != NIL) return T[T[u].p].l;
  if(T[T[u].p].r != u && T[T[u].p].r != NIL) return T[T[u].p].r;
  return NIL;
}
