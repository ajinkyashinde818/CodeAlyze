#include <stdio.h>
#include <stdlib.h>
#define M -1

typedef struct{
  int p; //親
  int r; //左の子
  int l; //右の子
}NODE;

void GetDepth(NODE *,int,int,int *);
int GetHeight(NODE *,int,int *);
int GetSibling(NODE *,int);

int main()
{
  int n,i,num,left,right,t,depth[100],height[100],degree;
  NODE T[26];

  scanf("%d",&n);
  if(n<1 || n>25) exit(1);
  for(i=0;i<n;i++) T[i].p = M;
  for(i=0;i<n;i++){
    scanf("%d %d %d",&num,&left,&right); //子を持たない場合は-1
    T[num].l = left;
    T[num].r = right;
    if(left != M) T[left].p = num; //子がいたら親を設定
    if(right != M) T[right].p = num; //同じ
  }

  for(i=0;i<n;i++)
    if(T[i].p == M) t=i; //rootを探す

  GetDepth(T,t,0,depth); //深さ獲得
  GetHeight(T,t,height); //高さ獲得

  for(i=0;i<n;i++){
    degree = 0;
    if(T[i].l != M) degree++; //次数のカウント
    if(T[i].r != M) degree++; //次数のカウント
    printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, ",i,T[i].p,GetSibling(T,i),degree,depth[i],height[i]);
    if(T[i].p == M) printf("root\n");
    else if(T[i].l == M && T[i].r == M) printf("leaf\n");
    else printf("internal node\n");
  }
  return 0;
}

void GetDepth(NODE *T,int t,int num,int *depth)
{
  if(t == M) return;
  depth[t] = num; //深さを与える
  if(T[t].r != M) GetDepth(T,T[t].r,num+1,depth); //右の兄弟に深さ+1
  if(T[t].l != M) GetDepth(T,T[t].l,num+1,depth); //左の兄弟に深さ+1
}

int GetHeight(NODE *T,int t,int *height)
{
  int h1=0,h2=0;

  if(T[t].l != M) h1 = GetHeight(T,T[t].l,height)+1; //子がいるなら高さ+1
  if(T[t].r != M) h2 = GetHeight(T,T[t].r,height)+1; //同じ
  return height[t] = (h1>h2 ? h1 : h2); //高い方を返して下に進んでいくイメージ
}

int GetSibling(NODE *T,int t)
{
  if(T[t].p == M) return M;
  if(T[T[t].p].l != t && T[T[t].p].l != M) return T[T[t].p].l; //左兄弟がrootでも空でもない場合、左の兄弟を返す
  if(T[T[t].p].r != t && T[T[t].p].r != M) return T[T[t].p].r; //右兄弟がrootでも空でもない場合、右の兄弟を返す
  return M;
}
