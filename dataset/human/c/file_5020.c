#include<stdio.h>
#include<stdlib.h>

#define MAX 100001

typedef struct{
  int parent;
  int left;
  int right;
} Node;

Node T[MAX];

int getDepth(int);
int getHeight(int);
int Degree(int);
int Sibling(int,int);
void PrintState(int);

int main(){
  int n,i,id,r,l;

  scanf("%d",&n);

  for(i = 0; i < n; i++){
    T[i].parent = -1;
    T[i].left = -1;
    T[i].right = -1;
  }

  for(i = 0; i < n; i++){
    scanf("%d%d%d",&id ,&r ,&l);

    T[r].parent = id;
    T[l].parent = id;
    T[id].left = r;
    T[id].right = l;
  }

  for(i=0; i<n; i++) PrintState(i);

  return 0;
}

int getDepth(int x){
  if(T[x].parent == -1) return 0;
  else return 1+getDepth(T[x].parent);
}

int getHeight(int x){
  int lefth = 0, righth = 0;

  if(x == -1) return 0;

  if(T[x].left != -1) lefth = getHeight(T[x].left)+1;
  if(T[x].right != -1) righth = getHeight(T[x].right)+1;

  if(lefth > righth) return lefth;
  else return righth;

}

int Degree(int x){
  if(T[x].left != -1 && T[x].right != -1) return 2;
  else if(T[x].left != -1 || T[x].right != -1) return 1;
  else return 0;
}

int Sibling(int parent,int x){
  if(parent == -1) return -1;
  else if(T[parent].left == x)return T[parent].right;
  else return T[parent].left;
}

void PrintState(int u){
  printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, " ,u ,T[u].parent ,Sibling(T[u].parent,u) ,Degree(u) ,getDepth(u) ,getHeight(u));

  if(T[u].parent == -1) printf("root\n");
  else if(T[u].left == -1 && T[u].right == -1) printf("leaf\n");
  else printf("internal node\n");
}
