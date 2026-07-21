#include <stdio.h>
#define MAX 100000
typedef struct{
  int parent,right,left;
}Node;

Node T[MAX];

int x,h[MAX],d[MAX];

void depth(int,int);
int height(int);
int sibling(int);
void print(int);

int main(){
  int n,i,id,left,right,root=0;

  scanf("%d",&n);

  for(i=0;i<n;i++){
    T[i].parent = -1;
  }

  for(i=0;i<n;i++){
    scanf("%d %d %d",&id,&left,&right);
    T[id].left = left;
    T[id].right = right;
    if(left != -1) T[left].parent = id;
    if(right != -1) T[right].parent = id;
  }
    for(i=0;i<n;i++){
      if(T[i].parent == -1) root = i;
    }
    
    depth(root,0);
    height(root);

    for(i=0;i<n;i++){
      print(i);
    }

    return 0;
}
void print(int x){
  int degree=0;
      printf("node %d: parent = %d,",x,T[x].parent);
      printf(" sibling = %d,",sibling(x));
      if(T[x].left != -1) degree++;
      if(T[x].right != -1) degree++;

      printf(" degree = %d,",degree);
      printf(" depth = %d, height = %d, ",d[x],h[x]);
      
      if(T[x].parent == -1) printf("root\n");
      else if(T[x].left == -1 && T[x].right == -1) printf("leaf\n");
      else printf("internal node\n");
}

int height(int x){
  int left=0,right=0;
  if(T[x].right != -1)  right = height(T[x].right)+1;
  if(T[x].left != -1) left = height(T[x].left) +1;
  if(T[x].right == -1 && T[x].left == -1) return 0;
  if(left > right) return h[x] = left;
  else return h[x] = right;
}

int sibling(int x){
  if(T[x].parent == -1) return -1;
  if(T[T[x].parent].left != x && T[T[x].parent].left != -1) return T[T[x].parent].left;
  if(T[T[x].parent].right  != x && T[T[x].parent].right != -1) return T[T[x].parent].right;

  return -1;
}

void depth(int x, int y){
  if(x == -1) return;
  d[x] = y;
  depth(T[x].left, y+1);
  depth(T[x].right, y+1);
}
