#include <stdio.h>
#define N 100005
#define NIL -1

struct Node{
  int p, l, r;
};
struct Node T[N];

int getDepth(int p){
  if(T[p].p == NIL) return 0;
  return getDepth(T[p].p) + 1;
}

int main(){
  int n, i, k, j, c;
  int id, tmp;
  int dep[N];

  scanf("%d", &n);
  for(i = 0; i < n; i++){
    T[i].l = T[i].p = T[i].r = NIL;
  }
  for(i = 0; i < n; i++){
    scanf("%d%d", &id, &k);
    for(j = 0; j < k; j++){
      scanf("%d", &c);
      if(j == 0){
	T[id].l = c;
	T[c].p = id;
	tmp = c;
      }else{
	T[tmp].r = c;
	T[c].p = id;
	tmp = c;
      }
    }    
  }
  for(i = 0; i < n; i++){
    dep[i] = getDepth(i);
  }
  
  for(i = 0; i < n; i++){
    printf("node %d: parent = %d, depth = %d, ", i, T[i].p, dep[i]);
    if(T[i].p == NIL){
      printf("root, [");
    }else if(T[i].l == NIL){
      printf("leaf, [");
    }else{
      printf("internal node, [");
    }
    if(T[i].l != NIL){
      printf("%d", T[i].l);
      tmp = T[i].l;
      while(1){
	if(T[tmp].r == NIL) break;
	printf(", %d", T[tmp].r);
	tmp = T[tmp].r;
      }
    }
      printf("]\n", tmp);
  }
  return 0;
}
