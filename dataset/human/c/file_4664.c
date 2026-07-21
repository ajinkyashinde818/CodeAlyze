#include<stdio.h>
#include<string.h>
#define MAX 25
#define LEN 14
#define NIL -1

typedef struct{
  int parent;
  int left; 
  int right; 
  char state[LEN]; 
  int depth; 
  int sib; 
  int deg; 
  int height; 
}Node;

void s_Dep(int, int);
int s_Hei(int, int);

Node t[MAX];

int main(){
  int n, a, parent, root;
  int i;

  scanf("%d",&n);

  for(i = 0; i < n; i++){
    t[i].parent = NIL;
    t[i].deg = 0;
  }
  
  for(i = 0; i < n; i++){
    scanf("%d", &a);
    scanf("%d %d", &t[a].left, &t[a].right);
    if(t[a].left != NIL) t[t[a].left].parent = a; 
    if(t[a].right != NIL) t[t[a].right].parent = a;
  }

  for(i = 0; i < n; i++){
    if(t[i].parent == NIL) root = i;
  }

  s_Dep(root, 0);
  s_Hei(root, 0);

  for(i=0;i<n;i++){

    if(t[i].parent == NIL) strcpy(t[i].state, "root");
    else if(t[i].left == NIL && t[i].right == NIL) strcpy(t[i].state, "leaf");
    else strcpy(t[i].state, "internal node");

    if(t[i].parent != NIL){
      parent = t[i].parent;
      if(t[parent].left != NIL && t[parent].left != i) t[i].sib = t[parent].left;
      else if(t[parent].right != NIL && t[parent].right != i) t[i].sib = t[parent].right;
      else t[i].sib = NIL;
    }
    else t[i].sib = NIL;

    if(t[i].left != NIL) t[i].deg++;
    if(t[i].right != NIL) t[i].deg++;
    printf("node %d: ", i);
    printf("parent = %d, ", t[i].parent);
    printf("sibling = %d, ", t[i].sib);
    printf("degree = %d, ", t[i].deg);
    printf("depth = %d, ", t[i].depth);
    printf("height = %d, ", t[i].height);
    printf("%s\n", t[i].state);
  }
  
  return 0;
}

void s_Dep(int u, int d){
  t[u].depth = d;
  if(t[u].left != NIL) s_Dep(t[u].left, d+1);
  if(t[u].right != NIL) s_Dep(t[u].right, d+1);
}

int s_Hei(int u, int h){
  int h1 = 0, h2 = 0;
  if(t[u].left != NIL) h1 = s_Hei(t[u].left, h) + 1;
  if(t[u].right != NIL) h2 = s_Hei(t[u].right, h) +1;
  if(h1 > h2){ 
    t[u].height = h1;
    return h1;
  }else{
   t[u].height = h2;
   return h2;
  }
}
