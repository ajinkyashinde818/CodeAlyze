#include <stdio.h>

int depth(int);
int get_height(int, int);
void retheight(int, int, int, int);

typedef struct {
  int parent, sibling, left, right, degree;
} Node;

Node tree[100001];
int n;
int count = 0, count_b = 0;
int count_c[100001];

int main(){

  int nownode, deg, left, right, i, j;

  scanf("%d", &n);

  for (i = 0; i < n; i++){
    tree[i].parent = tree[i].degree = tree[i].sibling = tree[i].left = tree[i].right = -1;
  }

  for (i = 0; i < n; i++){

    scanf("%d%d%d", &nownode, &left, &right);

    count = 0;
    if (left != -1){
      tree[left].parent = nownode;
      tree[left].sibling = right;
      tree[nownode].left = left;
      count++;
    }

    if (right != -1){
      tree[right].parent = nownode;
      tree[right].sibling = left;
      tree[nownode].right = right;
      count++;
    }

    tree[nownode].degree = count;
  }

  for(i = 0; i < n; i++){

    count = count_b = 0;

    printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, ", i,tree[i].parent, tree[i].sibling, tree[i].degree, depth(i), get_height(i, depth(i)));

    if(tree[i].parent == -1){
      printf("root\n");
    } else if(tree[i].left == -1 && tree[i].right == -1){
      printf("leaf\n");
    } else {
      printf("internal node\n");
    }
  }

  return 0;
}


int depth(int id) {

  if (tree[id].parent == -1) {
    return count / 2;
  } else {
    count++;
    return depth(tree[id].parent);
  }

}

int get_height(int id, int depth) {

  int i, ret = 0;

  for(i = 0; i < n; i++){
    count_c[i] = 0;
  }

  retheight(id, 0, depth, depth);

  for(i = 0; i < count_b + 1; i++){

    if(ret < count_c[i]){
      ret = count_c[i];
    }

  }
  return ret;

}

void retheight(int id, int count_id, int startdepth, int depth) {

  int i, c;

  for (i = 1; i < n; i++) {
    if (count_c[i] == 0) {
      c = i;
      break;
    }
  }
  
  if (tree[id].left != -1 && tree[id].right != -1) {

    count_c[count_id]++;
    count_c[c] = depth - startdepth + 1;
    retheight(tree[id].left, count_id, startdepth, depth + 1);
    retheight(tree[id].right, c, startdepth, depth + 1);

  } else if (tree[id].left != -1) {
    
    count_c[count_id]++;
    retheight(tree[id].left, count_id, startdepth, depth + 1);

  } else if (tree[id].right != -1) {

    count_c[count_id]++;
    retheight(tree[id].right, count_id, startdepth, depth + 1);

  } else {
    count_b = count_id;
  }

}
