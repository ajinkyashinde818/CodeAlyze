#include<stdio.h>
#define MAX 100000
#define NIL -1
typedef struct{
  int p;
  int l;
  int r;
}Node;

Node T[MAX];
int n,D[MAX],H[MAX];//深さを代入,高さを代入

void print(int node_num){
    int i,c,degree;
    printf("node %d: ",node_num);//引数の番号
    printf("parent = %d, ",T[node_num].p);//引数ノードの親
    printf("sibling = %d, ",getSibling(node_num));//兄弟
    if(T[node_num].l!=NIL)degree++;
    if(T[node_num].r!=NIL)degree++;
    printf("degree = %d, ",degree);
    printf("depth = %d, ",D[node_num]);
    printf("height = %d, ",H[node_num]);
    if(T[node_num].p==(-1)) printf("root\n");
    else if(T[node_num].l==NIL && T[node_num].r==NIL) printf("leaf\n");//lに子の一番左のノードを入れる
    else printf("internal node\n");
}
int Depth(int node_num,int p){
  if(node_num==NIL)return 0;
  D[node_num]=p;//初期pは0node uの深さを逐一入れる
  //初期化時全てのノードのp,r,lはNILになってる
  Depth(T[node_num].r,p+1);//今回は右も子供
  Depth(T[node_num].l,p+1);//子のノードがあればpをカウントしてnode_numを子に変更
}
int setHeight(int node_num){
int h1=0,h2=0;
if(T[node_num].l!=NIL) h1=setHeight(T[node_num].l)+1;//高さをカウントし一つ深い層から再帰する;
if(T[node_num].r!=NIL) h2=setHeight(T[node_num].r)+1;
if(h1>h2){
  H[node_num]=h1;
   return h1;
 }//どちらが最深部か比較
else{
  H[node_num]=h2;
   return h2;
}
}

int getSibling(int node_num){
  if(T[node_num].p==NIL)return NIL;
  if(T[T[node_num].p].l!=NIL && T[T[node_num].p].l!=node_num)return T[T[node_num].p].l;
  if(T[T[node_num].p].r!=NIL && T[T[node_num].p].r!=node_num)return T[T[node_num].p].r;
  return NIL;
}

int main(){
  int i,j,depth,left,right,d,node_num,root;//dは次数
  scanf("%d",&n);
    for(i=0;i<n;i++){
      T[i].l=T[i].r=T[i].p=NIL;
    }
    for(i=0;i<n;i++){//ノードの個数
      scanf("%d",&node_num);
      scanf("%d",&left);
      scanf("%d",&right);
      T[node_num].l=left;
      T[node_num].r=right;
      if(left !=NIL)T[left].p=node_num;
      if(right !=NIL)T[right].p=node_num;
      }
    for(i=0;i<n;i++){
      if(T[i].p==NIL)root=i;//root探し
    }
    Depth(root,0);
    setHeight(root);
for(i=0;i<n;i++) print(i);
return 0;
}
