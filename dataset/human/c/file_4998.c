#include<stdio.h>
#include<stdlib.h>

typedef struct d{
  int p;    // parent
  int s;    // sibling
  int deg;  // degree
  int dep;  // depth
  int h;    // height
  int left;
  int right;
}data;

data *tree;

void dataprinter(data out){
  puts("-----data-----");
  printf("p=%d s=%d deg=%d dep=%d h=%d left=%d right=%d\n"
  ,out.p, out.s, out.deg, out.dep, out.h, out.left, out.right);
  puts("=====data=====");
}

void init(int n){
  int i;
  tree = (data *)malloc(sizeof(data) * n);
  for(i=0; i<n; i++){
    tree[i].p = -1;
    tree[i].s = -1;
    tree[i].deg = 0;
    tree[i].dep = 0;
    tree[i].h = -1;
    tree[i].left = -1;
    tree[i].right = -1;
  }
}

void maketree(void){
  int id;

  scanf("%d ",&id);
  scanf("%d %d ",&tree[id].left, &tree[id].right);
  if(tree[id].left != -1){
    tree[tree[id].left].p = id;
    tree[tree[id].left].s = tree[id].right;
    tree[id].deg += 1;
  }
  if(tree[id].right != -1){
    tree[tree[id].right].p = id;
    tree[tree[id].right].s = tree[id].left;
    tree[id].deg += 1;
  }
}

int isParent(int i){
  if(tree[i].p == -1) return 0;
  else return (isParent(tree[i].p)) + 1;
}

void getHeight(int i, int h){
  if(tree[i].deg == 0) {
    tree[i].h = h;
  }

  if(tree[i].h < h){
    tree[i].h = h;
  }

  if(tree[i].p != -1){
    getHeight(tree[i].p, h+1);
  }
}

void printer(int n){
  int i;

  for(i=0; i<n; i++){
    printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, "
    , i, tree[i].p, tree[i].s, tree[i].deg, tree[i].dep, tree[i].h);
    if(tree[i].p == -1){
      puts("root");
    }
    else if(tree[i].deg == 0){
      puts("leaf");
    }
    else{
      puts("internal node");
    }
  }
}

int main(){
  int i, n;

  scanf("%d",&n);
  init(n);
  for(i=0; i<n; i++){
    maketree();
  }
  for(i=0; i<n; i++){
    tree[i].dep = isParent(i);

    getHeight(i, 0);

  }

  printer(n);

  return 0;
}
