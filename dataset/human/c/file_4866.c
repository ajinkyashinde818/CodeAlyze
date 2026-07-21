#include<stdio.h>
#include<stdlib.h>

typedef struct node{
  int id;
  int k;
  int sibling;
  struct node *right;
  struct node *left;
  struct node *p;
}node;

int getsibling(node);
int getdegree(node);
int getdepth(node);
int getheight(node*);
char* gettype(node);

int main(){

  int i;
  int n,id,left,right;

  //input
  scanf("%d",&n);
  node tree[n];
  for(i=0;i<n;i++){
    tree[i].p=NULL;
  }
  for(i=0;i<n;i++){
    scanf("%d%d%d",&id,&left,&right);
    tree[id].id=id;
    tree[id].k=0;
    //left
    if(left!=-1) tree[id].k++;
    tree[id].left=malloc(sizeof(node));
    tree[id].left=&tree[left];
    tree[left].sibling=right;
    tree[id].left->id=left;
    tree[left].p=&tree[id];
   
    //right
    if(right!=-1) tree[id].k++;
    tree[id].right=malloc(sizeof(node));
    tree[id].right=&tree[right];
    tree[right].sibling=left;
    tree[id].right->id=right;
    tree[right].p=&tree[id];
  }
  //output
  for(i=0;i<n;i++){
    printf("node %d: ",i);
    if(tree[i].p==NULL) printf("parent = -1, ");
    else printf("parent = %d, ",tree[i].p->id);
    printf("sibling = %d, ",getsibling(tree[i]));
    printf("degree = %d, ",getdegree(tree[i]));
    printf("depth = %d, ",getdepth(tree[i]));
    printf("height = %d, ",getheight(&tree[i]));
    printf("%s",gettype(tree[i]));
    printf("\n");
  }
  return 0;
}

int getsibling(node tree){
  if(tree.p==NULL) return -1;
  return tree.sibling;
}

int getdegree(node tree){
  return tree.k;
}
int getdepth(node tree){
  int count=0;
  node *q;
  
  if(tree.p==NULL) return 0;
  q=&tree;
  while(q->p!=NULL){
    q=q->p;
    count++;
  }
  return count;
}

int getheight(node *tree){
  int lh=0,rh=0;
  if(tree->k==0) return 0;
  lh=1+getheight(tree->left);
  rh=1+getheight(tree->right);
  if(lh>rh) return lh;
  return rh;
}
char* gettype(node tree){
  if(tree.p==NULL) return "root";
  if(tree.k>=1) return "internal node";
  else return "leaf";
}
