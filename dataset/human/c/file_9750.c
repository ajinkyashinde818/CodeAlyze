#include <stdio.h>
#define MAX 100005
#define NIL -1


typedef struct{
  int par;
  int left;
  int right;
}Node;

Node tree[MAX];
int depth[MAX];

void print(int);
int Depth(int,int);

int main(){

int n,i,j,num,deg,c,l,r;

scanf("%d",&n);

for(i = 0; i < n; i++){
  tree[i].par = tree[i].left = tree[i].right = NIL;
}
for(i = 0; i < n; i++){
  scanf("%d %d",&num,&deg);
  for(j = 0 ; j < deg;j++){
    scanf("%d",&c);
    if(j == 0)tree[num].left = c;
    else tree[l].right = c;
    l = c;
    tree[c].par = num;
  }
}

for(i = 0; i<n;i++){
  if(tree[i].par == NIL)r=i;
}
Depth(r,0);

for(i = 0;i < n; i++)print(i);

return 0;
}

void print(int x){
  int i,c;

  printf("node %d: ",x);
  printf("parent = %d, ",tree[x].par);
  printf("depth = %d, ",depth[x]);

  if(tree[x].par == NIL)printf("root, ");
  else if(tree[x].left == NIL)printf("leaf, ");
  else printf("internal node, ");

  printf("[");
  for(i = 0, c = tree[x].left; c !=NIL; i++,c = tree[c].right){
    if(i > 0)printf(", ");
    printf("%d",c);
  }
  printf("]\n");
}

int Depth(int x,int y){
  depth[x] = y;
  if(tree[x].right != NIL)Depth(tree[x].right,y);
  if(tree[x].left != NIL)Depth(tree[x].left,y+1);
}
