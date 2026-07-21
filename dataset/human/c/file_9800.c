#include <stdio.h>
#include <stdlib.h>
#define N 100000
#define M -1

typedef struct{
  int p; //parent
  int l; //左の子
  int r; //右兄弟
}NODE;

void GetDepth(NODE *,int,int,int *); //木、子の位置、深さ、深さ(保存用)

int main()
{
  int n,depth[N],i,node,degree,j,child,left,t,num;
  NODE T[N];

  scanf("%d",&n);
  if(n>N) exit(1);
  
  for(i=0;i<n;i++) T[i].p = T[i].l = T[i].r = M; //全部-1にすることで後でrootなどの判定ができる

  for(i=0;i<n;i++){
    scanf("%d %d",&node,&degree);
    for(j=0;j<degree;j++){
      scanf(" %d",&child);
      if(j==0) T[node].l = child; //一番左の子を設定
      else T[left].r = child; //左の子の右兄弟に設定
      left = child;
      T[child].p = node; //
    }
  }
  for(i=0;i<n;i++)
    if(T[i].p == M) t=i; //rootを探す

  GetDepth(T,t,0,depth);
      
  for(i=0;i<n;i++){
    printf("node %d: parent = %d, depth = %d, ",i,T[i].p,depth[i]);
    if(T[i].p == M) printf("root, ");
    else if(T[i].l == M) printf("leaf, ");
    else printf("internal node, ");
    printf("[");
    child = T[i].l;
    for(j=0;child!=M;j++){ 
      if(j>0) printf(", ");
      printf("%d",child);
      child = T[child].r; //右の兄弟にchildを移動していく→標準表示とループを抜ける判定ができる
    }
    printf("]\n");
  }
  
  return 0;
}

void GetDepth(NODE *T,int t,int num,int *depth)
{
  depth[t] = num; //深さを与える
  if(T[t].r != M) GetDepth(T,T[t].r,num,depth); //右の兄弟がいたら、右の兄弟に同じ深さ
  if(T[t].l != M) GetDepth(T,T[t].l,num+1,depth); //一番左の子に深さ+1
}
