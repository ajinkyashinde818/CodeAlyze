/*二分木*/
#include <stdio.h>
#define N 25

typedef struct node{
  int No;
  int depth;
  int height;
  int nchild;
  int sibling;
  int parent;
  struct node *left;
  struct node *right;
} Node;


void depth(Node *);
void height(Node *, Node *);

void depth(Node *temp){
  if(temp->left !=NULL && temp->right == NULL){
    temp->left->depth = temp->depth + 1;
    depth(temp->left);
  }
  else if(temp->right !=NULL &&  temp->left == NULL){
    temp->right->depth = temp->depth + 1;
    depth(temp->right);
  }
  else if(temp->left !=NULL && temp->right != NULL){
    temp->left->depth = temp->depth + 1;
    temp->right->depth = temp->depth + 1;
    depth(temp->left);
    depth(temp->right);
  }
}

void height(Node *a, Node *temp){
  if(a[temp->parent].height <= temp->height+1){
    a[temp->parent].height = temp->height+1;
  }
  if (temp->parent != -1){
    temp = &a[temp->parent];
    height(a,temp);
  }
  else return;
  
}


int main(){
  Node a[N];
  int i, j, n, l, r, num;

  scanf("%d", &n);

  for (i=0; i<n; i++){
    a[i].No = i;
    a[i].parent = -1;
    a[i].sibling = -1;
    a[i].depth = -2;
    a[i].height = -1;
  }

  /*以下のループによりsibling, degreeを決定*/
  for (i=0; i<n; i++){
    scanf("%d%d%d", &num, &l, &r);
    
    if(l != -1 && r != -1){
      a[num].nchild = 2;
      a[num].left = &a[l];
      a[num].right = &a[r];
      a[l].sibling = r;
      a[r].sibling = l;
      a[l].parent = a[num].No;
      a[r].parent = a[num].No;
    }
    
    else if (l != -1 && r == -1){
      a[num].nchild = 1;
      a[num].left = &a[l];
      a[num].right = NULL;
      a[l].sibling = -1;
      a[l].parent = a[num].No;
    }
    
    else if (l == -1 && r != -1){
      a[num].nchild = 1;
      a[num].right = &a[r];
      a[num].left = NULL;
      a[r].sibling = -1;
      a[r].parent = a[num].No;
    }
    
    else if (l == -1 && r == -1){
      a[num].nchild = 0;
      a[num].left = NULL;
      a[num].right = NULL;
      a[num].height = 0;
    }
  }

  /*rootのdepthを決定するループ*/
  for (i=0; i<n; i++){
    if(a[i].parent == -1){
      a[i].depth = 0;
      break;
    }
  }
  depth(&a[i]);/*depthを決定する関数*/

  /*heightを決定するループ*/
  for (i=0; i<n; i++){
    if (a[i].left == NULL && a[i].right == NULL){
      height(a, &a[i]);/*heightを決定する関数*/
    }
  }
  
  for (i=0; i<n; i++){
    printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, ", a[i].No, a[i].parent, a[i].sibling, a[i].nchild, a[i].depth, a[i].height);
    if (a[i].parent == -1) printf("root\n");
    else if (a[i].height == 0) printf("leaf\n");
    else printf("internal node\n");
  }
  

  return 0;
}
