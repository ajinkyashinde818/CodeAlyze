#include <stdio.h>
#define N 100005
#define NIL -1
 
struct Node{
  int p, left, right;
};

struct Node T[N];
int n;
 
int getDepth(int p){
  if(T[p].p == NIL) return 0;
  else{
    return getDepth(T[p].p) + 1; 
  }
}
 
int getHeight(int p){
  int count, max = 0,i;

  for(i = 0; i < n; i++){
    if(T[i].p == p){
    count = getHeight(i) + 1;
    if(max < count) max = count;
    }
  }
  return max;
}
 
main(){
  int c1, c2,i,id, tmp;
  int dep[N], hei[N], sib[N], deg[N];
 
  scanf("%d", &n);
  for(i = 0; i < n; i++){
    T[i].left = T[i].p = T[i].right = NIL;
    deg[i] = hei[i] = 0;
    sib[i] = deg[i] = NIL;
  }
  for(i = 0; i < n; i++){
    scanf("%d %d %d", &id, &c1, &c2);
 
    if(c1 == NIL && c2 == NIL){
      deg[id] = 0;
 
    }else if (c1 != NIL && c2 == NIL){
      T[c1].p = id;
      T[id].left = c1;
      deg[id] = 1;
 
    }else if(c1 == NIL && c2 != NIL){
      deg[id] = 1;
      T[c2].p = id;
      T[id].right = c2;
    }else{
      deg[id] = 2;
      T[c1].p = id;
      T[c2].p = id;
      T[id].left = c1;
      T[id].right = c2;
      sib[c1] = c2;
      sib[c2] = c1;
    }    
  }
  for(i = 0; i < n; i++){
    dep[i] = getDepth(i);
    hei[i] = getHeight(i);
  }
   
  for(i = 0; i < n; i++){
    printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, ", i, T[i].p, sib[i], deg[i], dep[i], hei[i]);
    if(T[i].p == -1){
      printf("root\n");
    }else if(T[i].left == NIL && T[i].right == NIL){
      printf("leaf\n");
    }else{
      printf("internal node\n");
    }
  }
  return 0;
}
