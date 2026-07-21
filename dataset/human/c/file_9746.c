#include<stdio.h>

#define MAX 100001

typedef struct{
  int parent;
  int right;
  int left;
}Tree;

Tree tree[MAX];
int n,D[MAX];

void count(int,int);

int main(){
  int i,j,d,v,c,left,right;

  scanf("%d",&n);

  for( i = 0 ; i < n ; i++ )
    {
      tree[i].parent = -1;
      tree[i].right = -1;
      tree[i].left = -1;
    }

  for( i = 0 ; i < n ; i++ )
    {
      scanf("%d%d",&v,&d);
      for( j = 0 ; j < d ; j++ )
	{
	  scanf("%d",&c);
	  if( j == 0 ) tree[v].left=c;
	  else tree[left].right = c;
	  left = c;
	  tree[c].parent = v;
	}
    }

  for( i = 0 ; i < n ; i++ ){
    if(tree[i].parent == -1) right =i;
  }

  count(right,0);

  for(i = 0 ; i < n ; i++ ){
printf("node %d: parent = %d, depth = %d, ",i,tree[i].parent,D[i]);
 if(tree[i].parent == -1 ) printf("root, [");
 else if(tree[i].left == -1 ) printf("leaf, [");
 else printf("internal node, [");  

 for(j = 0,c=tree[i].left;c!=-1;j++,c=tree[c].right){
   if(j) printf(", ");
   printf("%d",c);
 }
 printf("]\n");
  }

  return 0;
}

void count(int u,int p){
  D[u]=p;
  if(tree[u].right!=-1) count(tree[u].right,p);
  if(tree[u].left!=-1) count(tree[u].left,p+1);
}
