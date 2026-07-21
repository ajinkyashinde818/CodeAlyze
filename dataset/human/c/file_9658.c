#include<stdio.h>
void preParse(int,int);
void print(int);

typedef struct{
  int parent,child,sibling;
}node;

node tree[200000];
int depth[200000];

int main(){
  int n,i,j,l,r;
  int id,degree,c;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    tree[i].parent=-1;
    tree[i].child=-1;
    tree[i].sibling=-1;
  }
   for(i=0;i<n;i++){
     scanf("%d",&id);
     scanf("%d",&degree);
     for(j=0;j<degree;j++){
       scanf("%d",&c);
       if(j==0)
	 tree[id].child=c;
       else tree[l].sibling=c;
       l=c;
       tree[c].parent=id;
     }
  }

   for(i=0;i<n;i++){
     if(tree[i].parent==-1)
       r=i;
   }

   preParse(r,0);
   
   for(i=0;i<n;i++){
     print(i);
   }
  return 0;
}

void preParse(int u,int p){
  depth[u]=p;
  if(tree[u].sibling!=-1)
    preParse(tree[u].sibling,p);
  if(tree[u].child!=-1)
    preParse(tree[u].child,p+1);
}

void print(int u){
  int i,c;
  
  printf("node %d: ",u);
  printf("parent = %d, ",tree[u].parent);
  printf("depth = %d, ",depth[u]);

  if(tree[u].parent==-1)
    printf("root, ");
  else if(tree[u].child==-1)
    printf("leaf, ");
  else
    printf("internal node, ");

  printf("[");
  for(i=0,c=tree[u].child;c!=-1;i++,c=tree[c].sibling){
    if(i) printf(", ");
    printf("%d",c);
  }
  printf("]\n");
}
