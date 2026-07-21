#include <stdio.h>
#include <stdlib.h>

typedef struct{
  int parent;
  int left;
  int right;
}Node;

Node T[25];
int n;

void maigoCenter(void);
int findSibling(int);
int countDegree(int);
int findDepth(int);
int findHeight(int);
void printType(int);

int main(){
  int i, id;

  scanf("%d", &n);

  for(i=0; i<n; i++){
    scanf("%d", &id);
    scanf("%d%d", &T[id].left, &T[id].right);
    T[id].parent = -1;
  }

  maigoCenter();

  for(i=0; i<n; i++){
    printf("node %d: parent = %d, sibling = %d, ", i, T[i].parent, findSibling(i));
    printf("degree = %d, ", countDegree(i));
    printf("depth = %d, ", findDepth(i));
    printf("height = %d, ", findHeight(i));
    printType(i);
  }


  return 0;
}

void maigoCenter(void){
  int i;

  for(i=0; i<n; i++){
    if(T[i].left != -1){
      T[T[i].left].parent = i;
    }
    if(T[i].right != -1){
      T[T[i].right].parent = i;
    }
  }

} 

int findSibling(int n){
  if(T[n].parent != -1){
    if(T[T[n].parent].left == n){
      return T[T[n].parent].right;
    }else {
      return T[T[n].parent].left;
    }
  }
    return -1;
}

int countDegree(int n){
  int count = 0 ;

  if(T[n].left != -1) count++;
  if(T[n].right != -1) count++;

  return count;
}

int findDepth(int n){ 
  int depth, parent;

  if(T[n].parent == -1) return 0;

  parent = T[n].parent;

  for( depth = 1; T[parent].parent != -1; depth++){
    parent = T[parent].parent;
  }

  return depth;
}

int findHeight(int n){
  int left=0, right=0;

  if(T[n].right != -1){
    right = findHeight(T[n].right) + 1;
  }  
  if(T[n].left != -1){
    left = findHeight(T[n].left) + 1;
  }
  
  return (left>right)? left : right;

}

void printType(int n){
  if(T[n].parent == -1) printf("root\n");
  else if(T[n].left == -1 && T[n].right == -1) printf("leaf\n");
  else printf("internal node\n");
}
