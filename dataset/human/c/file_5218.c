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

  node T[25];
  scanf("%d",&n);
  
  for(i=0;i<n;i++){
    T[i].parent=-1;
    T[i].left=-1;
    T[i].right=-1;
  }

  for(i=0;i<n;i++){
    scanf("%d",&id);
    scanf("%d%d",&T[id].left,&T[id].right);
  }
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      if(i==T[j].left){
	T[i].parent=j;
      }
      if(i==T[j].right){
	T[i].parent=j;
      }
    }
  }
  
  for(i=0;i<n;i++){
    printf("node %d: parent = %d, ",i,T[i].parent);
    for(j=0,frag=0;j<n;j++){
      if(i==j) continue;
      if(T[i].parent==T[j].parent){
	printf("sibling = %d, ",j);
	++frag;
	break;
      }
    }
    if(frag==0) printf("sibling = -1, ");
    printf("degree = %d, ",degree(T,n,i));
    printf("depth = %d, ",depth(T,n,i));
    printf("height = %d, ",height(T,n,i));
    print_type(T,i);
  }

  return 0;
}

int degree(node *T,int n,int i){
  int count=0;
  int j;
  for(j=n-1;j>=0;j--){
    if(i==j) continue;
    if(i==T[j].parent){
      count++;
    }
  }
  return count;
}

int depth(node *T,int n,int i){
  int count=0;
  int j;
  for(j=0;j<n;j++){
      if(T[i].parent==j){
	count++;
	i=j;
	j=-1;
      }
  }
  
  
  return count;
}

int height(node *T,int n,int i){
  int count=0;
  int h1=0,h2=0;
  
  if(T[i].left!=-1) h1=height(T,n,T[i].left)+1;
  if(T[i].right!=-1) h2=height(T,n,T[i].right)+1;
  if(h1<h2) return h2;
  else return h1;
  
}

void print_type(node *T,int i){
    if(T[i].parent==NIL) printf("root\n");
    else if(T[i].left==NIL && T[i].right==NIL) printf("leaf\n");
    else printf("internal node\n");
}
