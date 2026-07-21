#include <stdio.h>

typedef struct Node{
  int parent;
  int left;
  int right;
}Tree;

Tree T[1000000];

void TreePrint(int);

int main(){
  int n, i, j, k ,l, id, child;

  scanf("%d",&n);
  for(i = 0;i <n;i++){
    T[i].parent = T[i].left = T[i].right = -1;
  }
  
  for(i = 0;i <n;i++){
    scanf("%d%d",&id, &k);
    
    for(j = 0;j < k;j++){
      scanf("%d",&child);
      
      T[child].parent = id;
      
      if(j == 0){
	T[id].left = child;
      }
      else if(j >0){
	T[l].right = child;
      }
      l = child;
    }
  }
  for(i = 0;i < n;i++){
    TreePrint(i);
  }
      return 0;
}

void TreePrint(int n){
  int i = T[n].parent;
  int dep = 0;

  while(i != -1){
    i = T[i].parent;
    dep++;
  }

  if(dep == 0){
    printf("node %d: parent = %d, depth = %d, root, ",n ,T[n].parent, dep);
  }

  else if(T[n].left == -1){
    printf("node %d: parent = %d, depth = %d, leaf, ",n ,T[n].parent, dep);
  }

  else{
    printf("node %d: parent = %d, depth = %d, internal node, ",n ,T[n].parent, dep);
  }

  i = T[n].left;
  printf("[");
  if(i != -1){

    printf("%d",i);
  }

  while(i != -1){
    i = T[i].right;

    if(i != -1){
      printf(", %d",i);
    }
  }
  printf("]\n");
}
