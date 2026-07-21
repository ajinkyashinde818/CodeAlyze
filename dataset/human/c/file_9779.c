#include<stdio.h>

struct Node_struct{int id, p, d, c, s;};
typedef struct Node_struct Node;
Node node[200000];

void dfs(int pos, int dep);

void root2(int par, int ro);

int main(){
  int i, j, k;
  int N;
  int id, sib, child;
  int root = 0;
  scanf("%d", &N);
  for(int i=0;i<N;i++) node[i].p = node[i].c = node[i].s = -1;

  for(i=0;i<N;i++){
    scanf("%d %d", &id, &k);
    node[id].id = id;
    for(j=0;j<k;j++){
      scanf("%d", &child);
      node[child].p = id;
      if(j == 0) node[id].c = child, sib = child;
      else node[sib].s= child;
      sib = child;
    }
  }


  for(i=0;i<N;i++) if(node[i].p == -1) root = i;
  dfs(root, 0);

  for(i=0;i<N;i++){
    printf("node %d: parent = %d, depth = %d, ", node[i].id, node[i].p, node[i].d);
    if(node[i].p == -1) printf("root, ");
    else if(node[i].c == -1) printf("leaf, ");
    else printf("internal node, ");
    printf("[");
    root2(node[i].c, 1);

  printf("]\n");
}


  return 0;
}

void root2(int par, int ro){
  if(par==-1){
    return;
  }
  if(ro){
    printf("%d",par);
  }else {
    printf(", %d",par);
  }
  if(node[par].s!=-1){
    root2(node[par].s,0);
  }
}


void dfs(int pos, int dep){
  node[pos].d = dep;
  if(node[pos].c != -1) dfs(node[pos].c, dep + 1);
  if(node[pos].s != -1) dfs(node[pos].s, dep);
}
