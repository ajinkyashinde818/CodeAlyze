#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
  int id;
  int left;
  int right;
  int parent;
  int sibling;
}tree;
tree *T;
int d = 0;
int degree(int i){
  int degree = 0;
  if(T[i].left != -1) degree++;
  if(T[i].right != -1) degree++;
  return degree;
}

int depth(int i){
  if(T[i].parent == -1) return d;
  else{
    d++;
    return depth(T[i].parent);
  }
}

int height(int i){
  int hl=0, hr=0;
  if(T[i].left != -1){
    hl++;
    hl += height(T[i].left);
  }
  if(T[i].right != -1){
    hr++;
    hr += height(T[i].right);
  }
  if(hr >= hl) return hr;
  else return hl;
}

int main(){
  int i, n, id;
  char s[20];

  scanf("%d",&n);
  T = malloc(sizeof(tree)*n);
  for(i = 0; i < n; i++){
    T[i].parent = -1;
    T[i].sibling = -1;
  }
  for(i = 0; i < n; i++){
    scanf("%d",&id);
    T[id].id = id;
    scanf("%d%d",&T[id].left, &T[id].right);
    T[T[id].left].parent = id;
    T[T[id].right].parent = id;
    T[T[id].left].sibling = T[id].right;
    T[T[id].right].sibling = T[id].left;
  }
  //print
  for(i = 0; i < n; i++){
    if(T[i].parent == -1) strcpy(s,"root");
    else if(T[i].left == -1 && T[i].right == -1) strcpy(s,"leaf");
    else strcpy(s,"internal node");
    printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, %s\n", i, T[i].parent, T[i].sibling, degree(i), depth(i), height(i), s);
    d = 0;
  }
  return 0;
}
