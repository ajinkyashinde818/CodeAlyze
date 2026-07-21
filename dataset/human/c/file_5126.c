#include <stdio.h>
#include <stdlib.h>
struct Node{
  int depth;
  int height;
  int p;//parent
  int l,r;
  int id;
  int c;
} ;

int getHeight(int);

struct Node *tree;
int main(){
  
  int i,j,n,a,id,c,x,y,x1,x2;
  
  scanf("%d",&n);
  tree = malloc(sizeof(struct Node)*n);
  
  for(i=0;i<n;i++){
    tree[i].p = tree[i].l = tree[i].r = -1;
  }
  for(i=0;i<n;i++){
    scanf("%d",&id);
    tree[id].id = id;
    scanf("%d%d",&tree[id].l,&tree[id].r);
  }
  
  for(i=0;i<n;i++){//getChildren
    tree[i].c=0;
    if(tree[i].l != -1)tree[i].c++;
    if(tree[i].r != -1)tree[i].c++;
  }
  
  for(i=0;i<n;i++){//findParent
    for(j=0;j<n;j++){
      if(tree[i].id == tree[j].l)tree[i].p = tree[j].id;
      else if(tree[i].id == tree[j].r)tree[i].p = tree[j].id;
    }
  }
  
  for(i=0;i<n;i++){//getDepth
    x=0;
    y=i;
    while(tree[y].p>-1){
      y = tree[y].p;
      x++;
    }
    tree[i].depth = x; 
  }

  for(i=0;i<n;i++){//getHeight
    x1=0;
    y=i;
    while(tree[y].l>-1){
      y = tree[y].l;
      x1++;
    }

    x2=0;
    y=i;
    while(tree[y].r>-1){
      y = tree[y].r;
      x2++;
    }
    
    if(x1>=x2)tree[i].height = x1;
    else if(x1<x2)tree[i].height = x2;
  }

  for(i=0;i<n;i++)tree[i].height = getHeight(i);
  
  
  for(i=0;i<n;i++){
    printf("node %d: parent = %d, ",i,tree[i].p);
    if (tree[i].p == -1)printf("sibling = -1, ");
    else if(tree[tree[i].p].l == i)printf("sibling = %d, ",tree[tree[i].p].r);
    else if(tree[tree[i].p].r == i)printf("sibling = %d, ",tree[tree[i].p].l);
    
    //getChildren;
    c=0;
    if(tree[i].l != -1)c++;
    if(tree[i].r != -1)c++;
    printf("degree = %d, ",c);
    
    printf("depth = %d, ",tree[i].depth);
    printf("height = %d, ",tree[i].height);
    
    
    
    
    if(tree[i].p == -1)printf("root");
    else if(tree[i].l == -1 && tree[i].r == -1)printf("leaf");
    else printf("internal node");
    printf("\n");
  }
  

  free(tree);
  
  
  return 0;
}

int getHeight(int i){
  int a=0,b=0;

  if(tree[i].l == -1 && tree[i].r == -1)return 0;
  else {
    if(tree[i].l != -1)a += getHeight(tree[i].l)+1;
    if(tree[i].r != -1)b += getHeight(tree[i].r)+1;
    if(a >= b) return a;
    else return b;
  }
}
