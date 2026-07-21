#include<stdio.h>
#include<stdlib.h>
#define N_MAX 100005
#define NIL -1

void print(int t);
int get_depth(int t);

struct node
{
  int parent;
  int left;
  int right;
};

struct node tree[N_MAX];


int get_depth(int t)
{
  int depth=0;
  while(tree[t].parent != NIL){
    t = tree[t].parent;
    depth ++;
  }
  
  return depth;
}


void print(int t)
{
  printf("node %d: ",t);

  printf("parent = %d, ",tree[t].parent);

  printf("depth = %d, ",get_depth(t));

  if(tree[t].parent == NIL){
    printf("root, ");
  }
  else if(tree[t].left == NIL){
    printf("leaf, ");
  }
  else{
    printf("internal node, ");
  }


  int c=tree[t].left;
  printf("[");
  while(c != NIL){
    printf("%d",c);
    c = tree[c].right;
    if(c != NIL){
      printf(", ");
    }
  }
  printf("]\n");
}



int main()
{
  int n, i, j;
  int id, k, c, left=0, r;

  scanf("%d", &n);
  
  for(i=0; i<n; i++){
    tree[i].parent=NIL;
    tree[i].left=NIL;
    tree[i].right=NIL;
  }

  
  for(i=0; i<n; i++){
    scanf("%d", &id);
    scanf("%d", &k);
    for(j=0; j<k; j++){
      scanf("%d", &c);
      if(j==0){
	tree[id].left = c;
      }
      else{
	tree[left].right = c;
      }
      left = c;
      tree[c].parent = id;
    }
  }

  
  for(i=0; i<n; i++){
    print(i);
  }
  
  return 0;
}
