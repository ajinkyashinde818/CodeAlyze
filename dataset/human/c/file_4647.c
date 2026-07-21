#include<stdio.h>
#include<stdlib.h>
  
typedef struct{
  int parent;
  int left;
  int right;
}node;
  
int degree(node*,int,int);
int depth(node*,int,int);
int height(node*,int,int);
void print_type(node*,int);
#define NIL -1
  
int main(){
  int n,id,frag,count;
  int i,j,k;
  int dep;
  
  node D[25];
  scanf("%d",&n);
    
  for(i=0;i<n;i++){
    D[i].parent=-1;
    D[i].left=-1;
    D[i].right=-1;
  }
  
  for(i=0;i<n;i++){
    scanf("%d",&id);
    scanf("%d%d",&D[id].left,&D[id].right);
  }
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      if(i==D[j].left){
    D[i].parent=j;
      }
      if(i==D[j].right){
    D[i].parent=j;
      }
    }
  }
    
  for(i=0;i<n;i++){
    printf("node %d: parent = %d, ",i,D[i].parent);
    for(j=0,frag=0;j<n;j++){
      if(i==j) continue;
      if(D[i].parent==D[j].parent){
    printf("sibling = %d, ",j);
    ++frag;
    break;
      }
    }
    if(frag==0) printf("sibling = -1, ");
    printf("degree = %d, ",degree(D,n,i));
    printf("depth = %d, ",depth(D,n,i));
    printf("height = %d, ",height(D,n,i));
    print_type(D,i);
  }
  
  return 0;
}
  
int degree(node *D,int n,int i){
  int count=0;
  int j;
  for(j=n-1;j>=0;j--){
    if(i==j) continue;
    if(i==D[j].parent){
      count++;
    }
  }
  return count;
}
  
int depth(node *D,int n,int i){
  int count=0;
  int j;
  for(j=0;j<n;j++){
      if(D[i].parent==j){
    count++;
    i=j;
    j=-1;
      }
  }
    
    
  return count;
}
  
int height(node *D,int n,int i){
  int count=0;
  int h1=0,h2=0;
    
  if(D[i].left!=-1) h1=height(D,n,D[i].left)+1;
  if(D[i].right!=-1) h2=height(D,n,D[i].right)+1;
  if(h1<h2) return h2;
  else return h1;
    
}
  
void print_type(node *D,int i){
    if(D[i].parent==NIL) printf("root\n");
    else if(D[i].left==NIL && D[i].right==NIL) printf("leaf\n");
    else printf("internal node\n");
}
