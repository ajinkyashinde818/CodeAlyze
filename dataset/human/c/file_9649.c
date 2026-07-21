#include <stdio.h>
#define NIL -1

typedef struct{
  int parent;
  int left;
  int right;
}node;

void setDepth(int,int);
void print(int);

node t[100000];
int n;
int d[100000];

int main(){
  int i,j,id,k,c,left,right,parent;
  scanf("%d",&n);

  for(i=0;i<=n-1;i++){
    t[i].parent=t[i].left=t[i].right=NIL;
  }

  for(i=0;i<=n-1;i++){
    scanf("%d%d",&id,&k);
    
    for(j=0;j<=k-1;j++){
      scanf("%d",&c);
      if(t[id].left==NIL)t[id].left=c;
      else t[left].right=c;
      left=c;
      t[c].parent=id;
    }
  }

  for(i=0;i<=n-1;i++){
    if(t[i].parent==NIL)right=i;
  }

  setDepth(right,0);

  for(i=0;i<=n-1;i++){
    print(i);
  }


  return 0;
}


void setDepth(int u,int p){
  d[u]=p;
  if(t[u].right!=NIL)setDepth(t[u].right,p);
  if(t[u].left!=NIL)setDepth(t[u].left,p+1);
}


void print(int u){
  int c,i;
  
  printf("node %d: ",u);
  printf("parent = %d, ",t[u].parent);
  printf("depth = %d, ",d[u]);
  if(t[u].parent==NIL)printf("root, ");
  else if(t[u].left==NIL)printf("leaf, ");
  else printf("internal node, ");
  printf("[");

  for(i=0,c=t[u].left;c!=NIL;i++,c=t[c].right){
    if(i)printf(", ");
    printf("%d",c);
  }
  printf("]\n");
}
