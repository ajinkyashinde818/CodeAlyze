#include<stdio.h>
#define N 100000

typedef struct{
  int parent,left,right;
}Node;

Node Tree[N];
void Print(int);
int depth(int);
int PrintChild(int);

main(){

  int i,n,id,k,c,q,j;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    Tree[i].parent=-1;
    Tree[i].left=-1;
    Tree[i].right=-1;
  }

  for(i=0;i<n;i++){
    scanf("%d %d",&id,&k);
    for(j=0;j<k;j++){
      scanf("%d",&c);
      Tree[c].parent=id;
      if(j==0) Tree[id].left=c;
      else Tree[q].right=c;
      q=c;
    }
  }
  for(i=0;i<n;i++){
    Print(i);
  }
  return 0;
}

void Print(int u){
  int i;
  printf("node %d: parent = %d, depth = %d, ",u,Tree[u].parent,depth(u));
  if(Tree[u].parent==-1) printf("root, [");
  else if(Tree[u].left==-1) printf("leaf, [");
  else printf("internal node, [");
  PrintChild(Tree[u].left);
  printf("]\n");
}

int PrintChild(int o){
  if(o==-1) return 0;
  if(Tree[o].right==-1) printf("%d",o);
  else {
    printf("%d, ",o);
    PrintChild(Tree[o].right);
  }
  return 0;
}
int depth(int o){
  if(Tree[o].parent==-1) return 0;
  return 1+depth(Tree[o].parent);
}
