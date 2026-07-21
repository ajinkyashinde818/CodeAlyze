#include <stdio.h>
#define N 100000

 struct Node{
  int left,right,p;
};

struct Node node[N];
int D[N],n;

void print(int u){
  int i,c;
  printf("node %d: ",u);
  printf("parent = %d, ",node[u].p);
  printf("depth = %d, ",D[u]);

  if(node[u].p == -1)
    printf("root, ");
  else if(node[u].left == -1){
    printf("leaf, ");
  }
  else {
    printf("internal node, ");
  }

  printf("[");
  for(i=0, c=node[u].left; c != -1; i++,c=node[c].right){
    if(i)printf(", ");
    printf("%d",c);
  }
  printf("]\n");
}

int depth(int i,int p){
  D[i] = p;
  if(node[i].right != -1) depth(node[i].right,p);
  if(node[i].left != -1) depth(node[i].left, p+1);
  return 0;
}

int main(){
  int i,j,c,d,v,left,right;

  scanf("%d",&n);
  for(i=0; i<n; i++)
    node[i].p = node[i].left = node[i].right = -1;

  for(i=0; i<n; i++){
    scanf("%d",&v);
    scanf("%d",&d);

    for(j=0; j<d; j++){
      scanf("%d",&c);
      if(j==0) node[v].left = c;
      else node[left].right = c;
      left = c;
      node[c].p = v;

    }
  }

  for(i=0; i<n; i++){
    if(node[i].p == -1) right = i;
  }

  depth(right,0);

  for(i=0; i<n; i++)/*{
    printf("node %d: ",i);
    printf("parent = %d, ",node[i].p);
    printf("depth = %d, ",D[i]);

    if(node[i].p == -1)
      printf("root, ");
    else if(node[i].left == -1){
      printf("leaf, ");
    }
    else {
      printf("internal node, ");
    }

    printf("[");
    for(i=0, c=node[i].left; c != -1; i++,c=node[c].right){
      if(i)printf(", ");
      printf("%d",c);
    }
    printf("]\n");

  }
  */
  print(i);
  return 0;
}
