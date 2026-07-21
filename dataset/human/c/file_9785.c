#include<stdio.h>
#include<stdlib.h>

#define MAX 100000
#define NIL -1
struct node{int p,l,r;};

struct node T[MAX];
int n,D[MAX];

void print(int);
void rec(int,int);


int main(){
  int i,j,d,v,c,l,r;
  scanf("%d",&n);
  for(i=0;i<n;i++) T[i].p=T[i].l=T[i].r=NIL;//必要な部分初期化
  for(i=0;i<n;i++){
    scanf("%d%d",&v,&d);//vはrootの値、dはrootの子供の数
    for(j=0;j<d;j++){//子供の数ぶん入力
      scanf("%d",&c);
      if(j==0)T[v].l=c;//１週目は最も左の子供をleftに
      else T[l].r=c;//２週目は最も右の子供をrighに
      l=c;
      T[c].p=v;//親を教えてあげる
    }
  }
  for(i=0;i<n;i++){
    if(T[i].p==NIL) r=i;//親がrootで最も右のものをrightに
  }

  rec(r,0);

  for(i=0;i<n;i++) print(i);
  return 0;
}

void print(int u){
  int i,c;
  printf("node %d: parent = %d, depth = %d, ",u,T[u].p,D[u]);

  if(T[u].p==NIL) printf("root, ");
  else if(T[u].l==NIL) printf("leaf, ");
  else printf("internal node, ");

  printf("[");

  for(i=0,c=T[u].l;c!=NIL;i++,c=T[c].r){
    if(i) printf(", ");
    printf("%d",c);
  }
  printf("]\n");
}

void rec(int u,int p){//再帰で深さを教えてあげる
  D[u] = p;
  if(T[u].r != NIL) rec(T[u].r,p);
  if(T[u].l != NIL) rec(T[u].l,p+1);
}
