#include <stdio.h>
#include <stdlib.h>
#define MAX 100000
#define NIL -1

typedef struct{
  int parent,left,right;
}family;

//int getDepth(int);
void setDepth(int,int);
void printchildren(int);

int D[MAX];
family t[MAX];

int main(){
  int n,i,j,id,k,child,pre,root = 0;

  scanf("%d",&n);
  for(i = 0;i < n;i++){
    t[i].parent = NIL;
    t[i].left = NIL;
    t[i].right = NIL;
  }
  for(i = 0;i < n;i++){
    scanf("%d",&id);
    scanf("%d",&k);
    //  printf("(1) %d %d",id,k);
    for(j = 0;j < k;j++){
      scanf("%d",&child);
      //    printf("child %d",child);
      if(j == 0) t[id].left = child;
      else t[pre].right = child;
      // if(j == k - 1) t[child].right = NIL;
      t[child].parent = id;

      pre = child;
    }
    
  }
  //  printchildren(child);
  //  printf("scan ok\n");
  for(i = 0;i < n;i++){
    if(t[i].parent == NIL) root = i;
  }
  // printf("nannka ok\n");
  setDepth(root,0);
  //printf("setdepth ok\n");
  
  //ここから自作
  for(i = 0;i < n;i++){
    printf("node %d: parent = %d, depth = %d, ",i,t[i].parent,D[i]);
    if(t[i].parent == NIL) printf("root, ");
    else if(t[i].left == NIL) printf("leaf, ");
    else printf("internal node, ");
    printchildren(i);
    //上は自作なため、不確定。
  }


  //depth どうするか

  return 0;
}

/*int getDepth(int u){
  int d = 0;
  while(t[u].parent != NIL){
    u = t[u].parent;
    d++;
  }
  return d;
  }*/

void setDepth(int u,int p){
  D[u] = p;
  if(t[u].right != NIL) setDepth(t[u].right,p);
  if(t[u].left != NIL) setDepth(t[u].left,p + 1);
}

void printchildren(int u){
  int c = t[u].left;
  printf("[");
  while(c != NIL){
    printf("%d",c);
    if(t[c].right != NIL) printf(", ");
    c = t[c].right;
  }
  printf("]\n");
}
