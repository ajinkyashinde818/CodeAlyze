#include<stdio.h>

typedef struct {int id, par, dep, child, sib;}Node;

Node node[200000];

void dfs(int pos, int dep){
  node[pos].dep = dep;
  if(node[pos].child != -1) dfs(node[pos].child, dep + 1);
  if(node[pos].sib != -1) dfs(node[pos].sib, dep);
}

void prChilds(int pos, int init){
  if(pos == -1) return;
  if(init) printf("%d", pos);
  else printf(", %d", pos);
  if(node[pos].sib != -1) prChilds(node[pos].sib, 0);
}

int main(){
  int i, j, k;
  int N;
  int id, sib, child;
  int root = 0;
  scanf("%d", &N);
  for(int i=0;i<N;i++) node[i].par = node[i].child = node[i].sib = -1;
  
  for(i=0;i<N;i++){
    scanf("%d %d", &id, &k);
    node[id].id = id;
    for(j=0;j<k;j++){
      scanf("%d", &child);
      node[child].par = id;
      if(j == 0) node[id].child = child, sib = child;
      else node[sib].sib = child;
      sib = child;
    }
  }


  for(i=0;i<N;i++) if(node[i].par == -1) root = i;
  dfs(root, 0);

  for(i=0;i<N;i++){
    printf("node %d: parent = %d, depth = %d, ", node[i].id, node[i].par, node[i].dep);
    if(node[i].par == -1) printf("root, ");
    else if(node[i].child == -1) printf("leaf, ");
    else printf("internal node, ");
    printf("[");
    prChilds(node[i].child, 1);
    printf("]\n");
  }
  

  return 0;
}
