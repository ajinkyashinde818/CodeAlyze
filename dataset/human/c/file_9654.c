#include<stdio.h>
#define NIL -1
#define N 100000

typedef struct _tree{
  int parent;
  int right;
  int left;
}tree;

tree T[N];

int D[N];

int depth(int,int);

void print(int);

int main(){
  int num,i,j;
  int v,d,c,l,r;

  scanf("%d",&num);
  for(i=0;i<num;i++) {
    T[i].parent = T[i].right = T[i].left = NIL;
  }

  for(i=0;i<num;i++){
    scanf("%d%d",&v,&d);
    for(j=0;j<d;j++){
      scanf("%d",&c);
      if(j==0) T[v].left = c;
      else T[l].right = c;
      l = c;
      T[c].parent = v;
    }
  }

  for(i=0;i<num;i++){
    if(T[i].parent == NIL) r = i;
  }

  depth(r,0);

  for(i=0;i<num;i++) {
    print(i);
    printf("\n");
  }

  return 0;


}

int depth (int x,int y)
{

  D[x] = y;
  if(T[x].right != NIL) depth(T[x].right,y);//右の兄弟に同じ深さを設定
  if(T[x].left != NIL) depth(T[x].left,y+1);//最も左の子に自分の深さを＋１

}

void print(int u){
  int i,c;

  printf("node %d: ",u);
  printf("parent = %d, ",T[u].parent);
  printf("depth = %d, ",D[u]);

  if(T[u].parent == NIL) printf("root, ");
  else if(T[u].left == NIL) printf("leaf, ");
  else printf("internal node, ");

  printf("[");
  for(i=0,c = T[u].left; c!=NIL;i++,c = T[c].right){
    if(i) printf(", ");
    printf("%d",c);
  }
  printf("]");

}
