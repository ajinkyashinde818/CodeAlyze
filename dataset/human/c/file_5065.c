#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ROOT 0
#define INTERNAL 1
#define LEAF 2

struct node {
  int id;
  int deg;
  int height;
  struct node *parent;
  int depth;
  int type;
  int child_id[2];
  struct node *child[2];
  struct node *sibling;
};

struct node *tree;

void set_depth(struct node *p);
int set_height(struct node *p);

int main(int argc, char *argv[])
{
  int i, j, n, num, ch;
  struct node *tmp;

  scanf("%d", &n);

  tree = (struct node *)malloc(sizeof(struct node) * n);

  for (i = 0; i < n; i++) tree[i].parent = NULL;

  for (i = 0; i < n; i++) {
    scanf("%d", &num);
    tree[num].id = num;

    tree[num].deg = 0;
    for (j = 0; j < 2; j++) {
      scanf("%d", &(tree[num].child_id[j]));
      if (tree[num].child_id[j] == -1) tree[num].child[j] = NULL;
      else {
	tree[num].deg++;
	ch = tree[num].child_id[j];
	tree[num].child[j] = &tree[ch];
	tree[ch].parent = &tree[num];
      }
    }

    if (tree[num].child[0] == NULL && tree[num].child[1] == NULL) {
      tree[num].type = LEAF;
    } else {
      tree[num].type = INTERNAL;
      if (tree[num].child[0] != NULL && tree[num].child[1] == NULL) {
	tree[num].child[0]->sibling = NULL;
      } else if (tree[num].child[0] == NULL && tree[num].child[1] != NULL) {
	tree[num].child[1]->sibling = NULL;
      } else {
	tree[num].child[0]->sibling = tree[num].child[1];
	tree[num].child[1]->sibling = tree[num].child[0];
      }
    }
  }

  for (i = 0; i < n; i++) {
    if (tree[i].parent == NULL) {
      tree[i].type = ROOT;
      break;
    }
  }
  set_depth(&tree[i]);
  set_height(&tree[i]);

  for (i = 0; i < n; i++) {
    printf("node %d: ", tree[i].id);
    
    if (tree[i].parent == NULL) printf("parent = -1, ");
    else printf("parent = %d, ", tree[i].parent->id);

    if (tree[i].sibling == NULL) printf("sibling = -1, ");
    else printf("sibling = %d, ", tree[i].sibling->id);
    
    printf("degree = %d, ", tree[i].deg);

    printf("depth = %d, ", tree[i].depth);

    printf("height = %d, ", tree[i].height);
    
    if (tree[i].type == ROOT) printf("root\n");
    else if (tree[i].type == INTERNAL) printf("internal node\n");
    else printf("leaf\n");
  }

  return 0;
}

void set_depth(struct node *p)
{
  int i;

  if (p->parent == NULL) p->depth = 0;
  else p->depth = p->parent->depth + 1;

  for (i = 0; i < 2; i++) {
    if (p->child[i] != NULL) set_depth(p->child[i]);
  }
}

int set_height(struct node *p)
{
  if (p->child[0] == NULL && p->child[1] == NULL) {
    p->height = 0;
  } else if (p->child[0] != NULL && p->child[1] == NULL) {
    p->height = set_height(p->child[0]) + 1;
  } else if (p->child[0] == NULL && p->child[1] != NULL) {
    p->height = set_height(p->child[1]) + 1;
  } else {
    p->height = (int)fmax(set_height(p->child[0]), set_height(p->child[1])) + 1;
  }

  return p->height;
}
