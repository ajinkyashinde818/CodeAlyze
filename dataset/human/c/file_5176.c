#include <stdio.h>
#define N 25

typedef struct node {
  int id;
  int depth;
  int height;
  int degree;
  int sibling;
  struct node* parent;
  struct node* left;
  struct node* right;
} NODE;

void calcDepth(NODE*);
void calcHeight(NODE*);

int main() {
  int i, j, n;
  int id, leftid, rightid;
  int root;
  NODE node[N];

  // input the number of nodes
  scanf("%d", &n);

  for(i = 0; i < n; i++) {
    node[i].parent = NULL;
    node[i].degree = 0;
    node[i].left = NULL;
    node[i].right = NULL;
  }

  // input the information of nodes
  for(i = 0; i < n; i++) {
    scanf("%d", &id);
    node[id].id = id;
    
    scanf("%d", &leftid);
    if(leftid != -1) {
      node[id].degree++;
      node[leftid].id = leftid;
      node[id].left = &node[leftid];
      node[leftid].parent = &node[id];
    }
    
    scanf("%d", &rightid);
    if(rightid != -1){
      node[id].degree++;
      node[rightid].id = rightid;
      node[id].right = &node[rightid];
      node[rightid].parent = &node[id];
    }
    
    // sibling
    if((leftid != -1)&&(rightid == -1)) {
      node[leftid].sibling = -1;
    }
    else if((leftid == -1)&&(rightid != -1)) {
      node[rightid].sibling = -1;
    }
    else if((leftid != -1)&&(rightid != -1)) {
      node[leftid].sibling = rightid;
      node[rightid].sibling = leftid;
    }
  }

  // depth
  i = 0;
  while(1) {
    if(node[i].parent == NULL){
      root = i;
      break;
    }
    i++;
  }
  calcDepth(&node[root]);
  calcHeight(&node[root]);

  // output
  for(i = 0; i < n; i++) {
    printf("node %d: ", i);
    // parent
    if(node[i].parent == NULL) printf("parent = -1, ");
    else printf("parent = %d, ", node[i].parent->id);
    // sibling
    if(node[i].parent == NULL) printf("sibling = -1, ");
    else printf("sibling = %d, ", node[i].sibling);
    // degree
    printf("degree = %d, ", node[i].degree);
    // depth
    printf("depth = %d, ", node[i].depth);
    // height
    printf("height = %d, ", node[i].height);
    // type
    if(node[i].parent == NULL) printf("root");
    else if((node[i].left == NULL)&&(node[i].right == NULL)) {
      printf("leaf");
    }
    else printf("internal node");
    printf("\n");
  }

  return 0;
}

void calcDepth(NODE* node) {
  // Preorder walk

  if(node == NULL) return;
  if(node->parent == NULL) node->depth = 0;
  else node->depth = node->parent->depth + 1;
  calcDepth(node->left);
  calcDepth(node->right);
}

void calcHeight(NODE* node) {
  // Postorder
  if(node == NULL) return;
  calcHeight(node->left);
  calcHeight(node->right);
  if((node->left == NULL)&&(node->right == NULL)) node->height = 0;
  else if((node->left != NULL)&&(node->right == NULL)) {
    node->height = node->left->height + 1;
  }
  else if((node->left == NULL)&&(node->right != NULL)) {
    node->height = node->right->height + 1;
  }
  else if(node->left->height > node->right->height) {
    node->height = node->left->height + 1;
  }
  else {
    node->height = node->right->height + 1;
  }
}
