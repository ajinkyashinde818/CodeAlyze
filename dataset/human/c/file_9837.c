#include<stdio.h>
#include<stdlib.h>

struct tree{
  int id;
  int p;
  int d;
  char *type;
  int *c;
  int k;
};

/*int pcheck(struct tree *T,int n, int id){
  int i, j;
  for(i=0; i<n; i++){
    for(j=0; j<T[i].k; j++){
      if(id == T[i].c[j]){
        return T[i].id;
      }
    }
  }
  return -1;
  }*/

int depth(struct tree *T, int d){
  if(T[d].p == -1){
    return 0;
  }
  else{
    return depth(T, T[d].p)+1;
  }
}

int main(){

  int n, i, k, j,cnt, id;
  struct tree *u, a;

  scanf("%d",&n);
  u = (struct tree *)malloc(sizeof(struct tree) * n);
  for(i=0; i<n; i++){
    u[i].p = -1;
  }
  for(i=0; i<n; i++){
    scanf("%d%d", &id, &k);
    u[id].id = id;
    u[id].c = (int *)malloc(sizeof(int) * k);
    u[id].k = k;
    u[id].d = 0;
    for(j=0; j<k; j++){
      scanf("%d", &u[id].c[j]);
      u[u[id].c[j]].p = u[id].id;
    }
  }

  for(i=0; i<n; i++){
    if(u[i].p == -1){
      u[i].type = "root";
    }
    else if(u[i].k!=0){
      u[i].type = "internal node";
    }
    else{
      u[i].type = "leaf";
    }

    u[i].d = depth(u, i);
    printf("node %d: parent = %d, depth = %d, %s, [", u[i].id, u[i].p, u[i].d, u[i].type);
    for(j=0; j<u[i].k-1; j++){
      printf("%d, ", u[i].c[j]);
    }
    if(u[i].k-1==j){
      printf("%d]\n", u[i].c[j]);
    }
    else{
      printf("]\n");
    }
  }

  return 0;
}
