#include<stdio.h>
#define MAX 10000
typedef struct{
  int parent,left,right;
}Node;

Node T[MAX];
int n, dep[MAX],hei[MAX];

void setdep(int value,int p){
  if(value==-1)return;
  dep[value]=p;
  setdep(T[value].left,p+1);
  setdep(T[value].right,p+1);
}

int sethei(int value){
  int hl=0,hr=0;
  if(T[value].left!=-1){
    hl=sethei(T[value].left)+1;
  }
  if(T[value].right!=-1){
    hr=sethei(T[value].right)+1;
  }

  if(hl>hr)return hei[value]=hl;
  else return hei[value]=hr;
}

int getsib(int value){
  if(T[value].parent==-1)return -1;
  if(T[T[value].parent].left!=value && T[T[value].parent].left!=-1)return T[T[value].parent].left;
  if(T[T[value].parent].right!=value && T[T[value].parent].right!=-1)return T[T[value].parent].right;
  return -1;
}

void print(int value){
  int d=0;
  printf("node %d: parent = %d, sibling = %d, ",value,T[value].parent,getsib(value));
  if(T[value].left!=-1)d++;
  if(T[value].right!=-1)d++;
  printf("degree = %d, depth = %d, height = %d, ",d,dep[value],hei[value]);
  if(T[value].parent==-1){
    printf("root\n");
  }
  else if(T[value].left==-1 && T[value].right==-1){
    printf("leaf\n");
  }
  else printf("internal node\n");
}

int main(){
  int i,id,left,right,root=0;
  scanf("%d",&n);

  for(i=0;i<n;i++){
    T[i].parent=-1;
  }
  for(i=0;i<n;i++){
    scanf("%d%d%d",&id,&left,&right);
    T[id].left=left;
    T[id].right=right;
    if(left!=-1)T[left].parent=id;
    if(right!=-1)T[right].parent=id;
  }
  for(i=0;i<n;i++){
    if(T[i].parent==-1)root=i;
  }
  setdep(root,0);
  sethei(root);
  for(i=0;i<n;i++)print(i);
  return 0;
}
