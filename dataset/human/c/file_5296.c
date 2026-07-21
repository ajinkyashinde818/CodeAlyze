#include<stdio.h>
#include<stdlib.h>
#define N 100001
#define B -1

typedef struct{
  int parent;
  int left;
  int right;
} Tree;

Tree T[N];

int sibilings(int);
int degree(int);
int depth_c(int);
int hight(int);
void print(int);

main(){
  int i,j,p,l,r,n;
  scanf("%d", &n);
  for(i=0; i<n; i++){
    T[i].parent = B;
    T[i].left = B;
    T[i].right = B;
  }
  for(i=0; i<n; i++){
    scanf("%d%d%d",&p,&l,&r);
    T[l].parent = p;
    T[r].parent = p;
    T[p].left = l;
    T[p].right = r;
   }
  for(i=0; i<n; i++){
    print(i);
   }
  return 0;
}

int sibilings(int a){
  if(T[a].parent == B){
    return -1;
  }
  else if(T[T[a].parent].left == a){
    return T[T[a].parent].right;
  }
  else return T[T[a].parent].left;
}

int degree(int b){
  if(T[b].left ==B && T[b].right == B){
    return 0;
  }
  else if(T[b].left !=B && T[b].right != B){
    return 2;
  }
  else 
    return 1;
}

int depth_c(int c){
  int count = 0;
  if(T[c].parent == B){
    return 0;
  }
  else{
    count = depth_c(T[c].parent) + 1;
    return count;
  }
}

int hight(int e){
  int lh = 0, rh = 0;
  if(T[e].left != B){
    lh = hight(T[e].left) + 1;
  }
   if(T[e].right != B){
    rh = hight(T[e].right) + 1;
  }
   if(lh < rh){
     return rh;
   }
   else
     return lh;
}

void print(int f){
  printf("node %d: parent = %d, sibling = %d, degree = %d, ",f, T[f].parent, sibilings(f),degree(f));
  printf("depth = %d, height = %d, ",depth_c(f),hight(f));
  if(T[f].parent == B){
    printf("root\n");
  }
  else if(T[f].left == B && T[f].right == B){
    printf("leaf\n");
  }
  else 
    printf("internal node\n");
}
