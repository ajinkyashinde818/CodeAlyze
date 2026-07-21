#include<stdio.h>
#define N 100000

typedef struct{
  int parent;
  int left;
  int right;
}Node;

int depth(int);
int height(int);

Node node[N];

int main(){
  int i, j, n, id, child;

  scanf("%d", &n);
  for(i = 0;i < n;i++){
    node[i].parent = node[i].left = node[i].right = -1;
  }
  for(i = 0;i < n;i++){
    scanf("%d", &id);
    for(j = 0;j < 2;j++){
      scanf("%d", &child);
      if(child != -1){
        node[child].parent = id;
        if(j == 0){
          node[id].left = child;
        }
        else{
          node[id].right = child;
        }
      }
    }
  }

  for(i = 0;i < n;i++){
    printf("node %d: parent = %d, sibling = ", i, node[i].parent);
    if(node[i].parent == -1){
      printf("-1, ");
    }
    else{
      if(node[node[i].parent].right == -1){
        if(node[node[i].parent].left != -1 && node[node[i].parent].left != i){
          printf("%d, ", node[node[i].parent].left);
        }
        else{
          printf("-1, ");
        }
      }
      else{
        if(node[node[i].parent].right != i){
          printf("%d, ", node[node[i].parent].right);
        }
        else{
          printf("%d, ", node[node[i].parent].left);
        }
      }
    }

    printf("degree = ");
    if(node[i].left == -1){
      if(node[i].right == -1){
        printf("0, ");
      }
      else{
        printf("1, ");
      }
    }
    else{
      if(node[i].right == -1){
        printf("1, ");
      }
      else{
        printf("2, ");
      }
    }

    printf("depth = %d, height = %d, ", depth(i), height(i));

    if(node[i].parent == -1){
      printf("root\n");
    }
    else{
      if(node[i].left == -1){
        if(node[i].right != -1){
          printf("internal node\n");
        }
        else{
          printf("leaf\n");
        }
      }
      else{
        printf("internal node\n");
      }
    }
  }
  return 0;
}

int depth(int id){
  int dep = 0;
  while(1){
    if(node[id].parent == -1){
      return dep;
    }
    else{
      dep++;
      id = node[id].parent;
    }
  }
}

int height(int id){
  int hei, l = 0, r = 0;
  if(node[id].left == -1){
    if(node[id].right == -1){
      return 0;
    }
    else{
      r += height(node[id].right) + 1;
    }
  }
  else{
    l += height(node[id].left) + 1;
    if(node[id].right != -1){
      r += height(node[id].right) + 1;
    }
  }
  if(l < r){
    return r;
  }
  else{
    return l;
  }
}
