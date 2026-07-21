#include<stdio.h>
#define MAX 100005
#define NIL -1

typedef struct{
  int parent, left, right;
}Node;

Node Tree[MAX];
int Depth[MAX];
int Height[MAX];
int degree[MAX];
int h;

int getDepth(int);
int getHeight(int);
void print(int);


int main(void){
  int i, n;
  int vertex;
  int child[2];


  scanf("%d", &n);

  for ( i = 0; i < n; i++ ) {
    Tree[i].parent = NIL;
    Tree[i].left = NIL;
    Tree[i].right = NIL;
  }

  for ( i = 0; i < n; i++ ){
    scanf("%d %d %d", &vertex, &child[0], &child[1]);

    //子どもがいない場合はdegreeは0である。
    if(child[0] == NIL && child[1] == NIL)
      degree[vertex] = 0;

    //子どもがどちらかにいればdegreeは1である。
    else if(child[0] == NIL && child[1] != NIL){
      degree[vertex] = 1;
      Tree[child[1]].parent = vertex;
      Tree[vertex].right = child[1];
    }
    
    else if(child[0] != NIL && child[1] == NIL){
      degree[vertex] = 1;
      Tree[child[0]].parent = vertex;
      Tree[vertex].left = child[0];
    }


    //子どもが両方存在するという事はdegreeは2という事
    else{
      degree[vertex] = 2;
      Tree[child[0]].parent = vertex;
      Tree[child[1]].parent = vertex;
      
      Tree[vertex].left = child[0];
      Tree[vertex].right = child[1];
    }
  }

  for(i = 0;i < n; i++){
    Height[i] = getHeight(i);
  }

  for ( i = 0; i < n; i++ )
    Depth[i] = getDepth(i);
  
  for ( i = 0; i < n; i++ )
    print(i);
  
  return 0;
}

int getHeight(int u){
  int l = Tree[u].left;
  int r = Tree[u].right;
  int heightL = 0;
  int heightR = 0;

  if(l == NIL && r == NIL){
    return 0;
  }

  if(l != NIL){
    heightL = getHeight(l) + 1;
  }

  if (r != NIL){
    heightR = getHeight(r) + 1;
  }

  if(heightL < heightR){
    return heightR;
  }
  else{
    return heightL;
  }
}


int getDepth(int u){
  int d = 0;

  while(Tree[u].parent >= 0){
    u = Tree[u].parent;
    d++;
  }

  return d;
}

void print(int u){
  int index = Tree[u].parent;

  printf("node %d: parent = %d, ",u, Tree[u].parent);
  if(index == NIL){
    printf("sibling = %d, ",NIL);
  }
  else if(Tree[index].right != u){
    printf("sibling = %d, ",Tree[index].right);
  }
  else if(Tree[index].left != u){
    printf("sibling = %d, ",Tree[index].left);
  }
    
  printf("degree = %d, depth = %d, height = %d, ",degree[u], Depth[u], Height[u]);

  if(Tree[u].parent == NIL)
    printf("root\n");

  else if(degree[u] == 0)
    printf("leaf\n");


  else if(2 >= degree[u] && degree[u] >= 1)
    printf("internal node\n");

  
}
