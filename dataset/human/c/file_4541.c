#include <stdio.h>
#include <stdlib.h>

#define N 25

typedef struct{
  int id;
  int right;
  int left;
  int parent;
  int sibling;
  int degree;
  int depth;
  int height;

}NODE;

void tmpa(NODE *, int);
void parent(NODE *, int);
void depth(NODE *, int);
int height(NODE *, int);

int main(){

  int i, j;
  int n, set;
  NODE a[N];
  
  scanf("%d", &n);
  
  for(i = 0; i < n; i++){
    scanf("%d%d%d", &a[i].id, &a[i].left, &a[i].right);
    
  }
  
  tmpa(a, n);
  parent(a, n);

  for(i = 0; i < n; i++){
    if(a[i].parent == -1){
      a[i].depth = 0;
      set = i;
    }
  }

  depth(a, set);

  for(i = 0; i < n; i++){
    a[i].height = height(a, a[i].id);
  }  

  for(i = 0; i < n; i++){
    printf("node %d: parent = %d, sibling = %d, ", a[i].id, a[i].parent, a[i].sibling);
    printf("degree = %d, depth = %d, height = %d, ", a[i].degree, a[i].depth, a[i].height);
    if(a[i].parent == -1) printf("root\n");
    else if(a[i].degree > 0) printf("internal node\n");
    else printf("leaf\n");

  }  

  return 0;
}

void tmpa(NODE *a, int n){

  int i, j;
  NODE tmp;
  
  for(i = 0; i < n; i++){
    for(j = 0; j < n; j++){
      if(a[j].id != j){
	tmp = a[a[j].id];
	a[a[j].id] = a[j];
	a[j] = tmp;
      }
    
    }
  }  

}

void parent(NODE *a, int n){

  int i;

  for(i = 0; i < n; i++){
    a[i].parent = -1;
    a[i].sibling = -1;
    a[i].degree = 0;
    if(a[i].right != -1) a[i].degree++;
    if(a[i].left != -1) a[i].degree++;
  }

  for(i = 0; i < n; i++){
    
    if(a[i].right != -1){
      a[a[i].right].parent = a[i].id;
      a[a[i].right].sibling = a[i].left;

    }

    if(a[i].left != -1){
      a[a[i].left].parent = a[i].id;
      a[a[i].left].sibling = a[i].right;

    }

  }

}

void depth(NODE *a, int n){

  if(a[n].right != -1){
    a[a[n].right].depth = a[n].depth + 1;
    depth(a, a[n].right);
    
  }
   
  if(a[n].left != -1){
    a[a[n].left].depth = a[n].depth + 1;
    depth(a, a[n].left);
    
  }
 
}

int height(NODE *a, int n){

  int r = 1, l = 1;

  if(a[n].right == -1 && a[n].left == -1) return 0;

  if(a[n].right != -1){
    r += height(a, a[n].right);
  }
  
  if(a[n].left != -1){
    l += height(a, a[n].left);
  }
  
  if(r >= l) return r;
  else return l;

}
