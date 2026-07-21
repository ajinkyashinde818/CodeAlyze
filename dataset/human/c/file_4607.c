#include<stdio.h>
#include<stdlib.h>
struct node{
  int key;
  int depth;
  struct node *parent;
  struct node *left;
  struct node *right;
};
typedef struct node *Node;
int degree(Node);

void calcDepth(Node T,int p){
  T->depth = p;
  if(T->right!=NULL) calcDepth(T->right,p+1);
  if(T->left!=NULL) calcDepth(T->left,p+1);
}

int height(Node T){
  int kr=0,kl=0;
    if(T->right!=NULL) kr=height(T->right)+1;
  if(T->left!=NULL) kl=height(T->left)+1;
  if(kr>=kl) return kr;
  else return kl;
}

int main(){
  struct node T[25];
  int n;
  int i;
  int id,leftid,rightid;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    T[i].parent=NULL;
  }
  for(i=0;i<n;i++){
    scanf("%d %d %d",&id,&leftid,&rightid);
    T[id].key=id;
    if(leftid>=0){
      T[id].left=&T[leftid];
    T[leftid].parent=&T[id];
    }
    else T[id].left=NULL;
    if(rightid>=0){
      T[id].right=&T[rightid];
    T[rightid].parent=&T[id];
    }
    else T[id].right=NULL;
  }

  for(i=0;i<n;i++){
    if(T[i].parent==NULL) calcDepth(&T[i],0);
    }
  
  for(i=0;i<n;i++){
    printf("node %d: ",T[i].key);
     if(T[i].parent==NULL) printf("parent = -1, ");
       else printf("parent = %d, ",T[i].parent->key);
   printf("sibling = ");
    if(T[i].parent==NULL || T[i].parent->left==NULL || T[i].parent->right==NULL) printf("-1, ");
     else if(T[i].parent->left->key==T[i].key) printf("%d, ",T[i].parent->right->key);
    else printf("%d, ",T[i].parent->left->key);
    printf("degree = %d, ",degree(&T[i]));
    printf("depth = %d, ",T[i].depth);
     printf("height = %d, ",height(&T[i]));
    if(T[i].parent==NULL) printf("root");
     else if(T[i].right==NULL && T[i].left==NULL) printf("leaf");
     else printf("internal node");
    printf("\n");
  }
  return 0;
  }

int degree(Node T){
  int d=0;
  if(T->left!=NULL) d++;
  if(T->right!=NULL) d++;
  return d;
}
