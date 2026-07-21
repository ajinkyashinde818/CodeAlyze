#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
  int id;
  struct _node *parent;
  struct _node *child;
  struct _node *sibling;
} Node;

typedef Node* NodePointer;

int main () {
  NodePointer NodeArray;
  int n;
  
  scanf("%d", &n);
  NodeArray = (NodePointer)malloc(sizeof(Node)*n);

  for (int i = 0; i < n; i++) {
    NodeArray[i].id = i;
    NodeArray[i].parent  = NULL;
    NodeArray[i].child   = NULL;
    NodeArray[i].sibling = NULL;
  }
  
  for (int i = 0; i < n; i++) {
    int id, k;
    scanf("%d %d", &id, &k);

    int c, s;
    for (int j = 0; j < k; j++) {
      scanf("%d", &c);

      if (j == 0) {
	NodeArray[id].child = &NodeArray[c];
      } else {
	NodeArray[s].sibling = &NodeArray[c];
      }
      NodeArray[c].parent = &NodeArray[id];

      s = c;
    }
  }

  for (int i = 0; i < n; i++) {
    printf("node %d: ", NodeArray[i].id);
    printf("parent = %d, ", NodeArray[i].parent == NULL ? -1 : NodeArray[i].parent->id);
    int d = 0;
    NodePointer tmp = &NodeArray[i];
    while (tmp->parent != NULL) {
      d++;
      tmp = tmp->parent;
    }
    printf("depth = %d, ", d);
    printf("%s, ", NodeArray[i].parent == NULL ? "root" : NodeArray[i].child == NULL ? "leaf" : "internal node");
    printf("[");
    if (NodeArray[i].child != NULL) {
      printf("%d", NodeArray[i].child->id);
      tmp = NodeArray[i].child->sibling;
      while (tmp != NULL) {
	printf(", %d", tmp->id);
	tmp = tmp->sibling;
      }
    }
    printf("]\n");
  }
  
  free(NodeArray);
  
  return 0;
}
