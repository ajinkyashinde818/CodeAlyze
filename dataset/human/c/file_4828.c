#include <stdio.h>
#define NIL -1

int depth(int);
int sibling(int);
int degree(int);
int hight(int);
void print();

struct Node{
  int parent;
  int left;
  int right;
};

struct Node T[1000001];
int num=0;
int i,j,n,id,c1,c2,r,l;
int ids[100001];
int k;

int main(){

  scanf("%d",&n);

  for(i=0;i<n;i++){
    T[i].parent=NIL;
    T[i].left=NIL;
  }

  for(i=0;i<n;i++){
    scanf("%d%d%d",&id,&l,&r);
    ids[i]=id;
    T[id].left=l;
    T[id].right=r;
    T[l].parent=id;
    T[r].parent=id;
  }

  for(i=0;i<n;i++){
    num=0;
    printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, ",i,T[i].parent,sibling(i),degree(i),depth(i),height(i));
    if(T[i].parent==NIL){
      printf("root");
      printf("\n");
    }
    else if( T[i].left>=0 || T[i].right>=0){
      printf("internal node");
      printf("\n");
    }
    else if(T[i].left==NIL) printf("leaf\n");
  }

  return 0;
}

int depth(int t){
  int p=T[t].parent;
  if(p==NIL) return num;
  num++;
  depth(p);
}

int sibling(int t){
  int i;
  for(i=0;i<n;i++){
    if(T[t].parent == T[i].parent && t != i){
      return i;
    }
  }
  return -1;
}

int height(int t){
  int lefth=0,righth=0;
  if(T[t].left != NIL){
    lefth = height(T[t].left) + 1;
  }
  if(T[t].right != NIL){
    righth = height(T[t].right) + 1;
  }
  if(lefth > righth)  return lefth;
  else return righth;
}

int degree(int t){

  int n=0,s;
  if(T[t].left>=0) {
    n++;
    if(T[t].right>=0){
      n++;
    }
    return n;
  }

  if(T[t].right>=0){
    n++;
    return n;
  }
  return n;
}
