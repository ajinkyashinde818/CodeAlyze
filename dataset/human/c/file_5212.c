#include <stdio.h>

#define MAX 25

void Depth(int,int);
int Height(int);
int Sibling(int);
int degree(int);

struct Node{
  int parent;
  int left;
  int right;
};

struct Node T[MAX];
int Dep[MAX];
int High[MAX];

int main(){
  int i=0;
  int n=0;
  int id=0;
  scanf("%d",&n);

  for(i=0;i<n;i++){
    T[i].parent=-1;
  }

  for(i=0;i<n;i++){
    scanf("%d",&id);
    scanf("%d%d",&T[id].left,&T[id].right);
    if(T[id].left!=-1)T[T[id].left].parent=id;
    if(T[id].right!=-1)T[T[id].right].parent=id;
  }

  for(i=0;i<n;i++) if(T[i].parent==-1)break;
  Depth(i,0);
  Height(i);

  for(i=0;i<n;i++){
    printf("node %d: ",i);
    printf("parent = %d, ",T[i].parent);
    printf("sibling = %d, ",Sibling(i));
    printf("degree = %d, ", degree(i));
    printf("depth = %d, ", Dep[i]);
    printf("height = %d, ",High[i]);

    if(T[i].parent==-1) printf("root");
    else if(T[i].left==-1 && T[i].right==-1) printf("leaf");
    else printf("internal node");
    printf("\n");
  }
  
}

void Depth(int id,int d){
  Dep[id]=d;
  if(T[id].right!=-1) Depth(T[id].right,d+1);
  if(T[id].left!=-1)Depth(T[id].left,d+1);
}

int Height(int id){
  int h_left=0;
  int h_right=0;
  if(T[id].left!=-1) h_left=Height(T[id].left)+1;
  if(T[id].right!=-1) h_right=Height(T[id].right)+1;
  if(h_left>h_right) High[id]=h_left;
  else High[id]=h_right;
  return High[id];
}

int Sibling(int id){
  if(T[id].parent==-1) return -1;
  if(T[T[id].parent].left!=id && T[T[id].parent].left!=-1)
    return T[T[id].parent].left;
  else if(T[T[id].parent].right!=id && T[T[id].parent].right!=-1)
    return T[T[id].parent].right;
  else return -1;
}

int degree(int id){
  int deg=0;
  if(T[id].left!=-1)deg++;
  if(T[id].right!=-1)deg++;
  return deg;
}
