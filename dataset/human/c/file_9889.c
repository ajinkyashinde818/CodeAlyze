#include <stdio.h>
 
void degree(int);
int depth(int);
 
typedef struct{
  int parent;
  int left;
  int right;
}Node;
 
Node nodes[100001];
int counter = 0;
 
int main(void) {
 
  int i, j, n, m, new_node, child, left, right;
 
  scanf("%d", &n);
 
  for(i = 0; i < n; i++) {
    nodes[i].parent = -1;
    nodes[i].left = -1;
    nodes[i].right = -1;
  }
 
  for(i = 0; i < n; i++) {
    scanf("%d%d", &new_node, &m);
 
    for(j = 0; j < m; j++) {
      scanf("%d", &child);
      nodes[child].parent = new_node;
      if(j != 0)   nodes[left].right = child;
      else         nodes[new_node].left = child;
      left = child;
 
    }
  }
 
  for(i = 0; i < n; i++) {
    counter = 0;
    printf("node %d: parent = %d, depth = %d, ", i, nodes[i].parent, depth(i));
 
    if(nodes[i].parent == -1)       printf("root, [");
    else if (nodes[i].left == -1)   printf("leaf, [");
    else                            printf("internal node, [");
    
    counter = 0;
    degree(nodes[i].left);
    printf("]\n");
  }
  return 0;
}
 
int depth(int node_num) {
 
  if(nodes[node_num].parent == -1) {
    return counter;
  } else {
    counter++;
    return depth(nodes[node_num].parent);
  }
 
}
 
void degree(int node_num) {
 
  if(node_num != -1) {
 
    if(counter != 0)      printf(", ");
    printf("%d", node_num);
    counter++;
    degree(nodes[node_num].right);
     
  }
}
