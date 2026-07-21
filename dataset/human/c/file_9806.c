#include <stdio.h>

#define N 100000
#define TYPE {"root", "internal node", "leaf"}

typedef struct{
  int parent;
  int leftChild;
  int rightSbling;
} Node;

void printNode(Node *, int);
void printChild(Node *, int);
int nodeDepth(Node *, int);

int main() {
  int n, id, k, c, left;
  int i, j;
  Node node[N];

  scanf("%d", &n);

  for (i = 0; i < n; i++) {
     node[i].parent = -1;
     node[i].leftChild = -1;
     node[i].rightSbling = -1;
  }

  for (i = 0; i < n; i++) {
    scanf("%d %d", &id, &k);
    
    for (j = 0; j < k; j++) {
      
      scanf("%d", &c);
      node[c].parent = id;
      
      if (j == 0) {
	node[id].leftChild = c;
	left = c;
	continue;
      }
      
      node[left].rightSbling = c;
      left = c;
    }
  }

  for (i = 0; i < n; i++) {
    printNode(node, i);
  }
  
  return 0;
}

void printNode(Node *node, int id){
  int t;
  char *type[] = TYPE;
  
  printf("node %d: ", id);
  printf("parent = %d, ", node[id].parent);
  printf("depth = %d, " ,nodeDepth(node, id));
  
  if (node[id].parent == -1) t = 0;
  else if (node[id].leftChild != -1) t = 1;
  else t = 2;
  printf("%s, [", type[t]);

  if (t != 2) {
    printChild(node, id);
  }
  
  printf("]\n");
}

void printChild(Node *node, int id){
  int c = node[id].leftChild;

  if (c == -1) {
    return;
  }
  
  printf("%d", c);
  
  while (node[c].rightSbling != -1) {
    printf(", %d", node[c].rightSbling);
    c = node[c].rightSbling;
  }
}

int nodeDepth(Node *node, int id){
  int cnt = 0;
  
  while(node[id].parent != -1){
    cnt++;
    id = node[id].parent;
  }
  return cnt;
}
