#include<stdio.h>

#define MAX 100000



typedef struct{
  int parent;
  int left;
  int right;
  int degree;
}node;

int getdepth(int);
int getsibling(int);
int getheight(int);

node T[MAX];

int main(){
  int i, j, sib, deg, id, k, n, depth;

  scanf("%d",&n);

  for(i=0;i<n;i++) T[i].parent = T[i].left = T[i].right = -1;

  for(i=0 ; i<n ; i++){

    scanf("%d",&id);
    scanf("%d%d",&T[id].left,&T[id].right);
    if(T[id].left != -1){
      T[T[id].left].parent = id;
      T[id].degree++;
    }
    if(T[id].right != -1){
      T[T[id].right].parent = id;
      T[id].degree++;
    }
/*
    for(j=0 ; j<k ; j++){

      scanf("%d",&deg);

      if(j==0) T[id].left = deg;

      else T[sib].right = deg;

      sib = deg;
      T[deg].parent = id;
    }*/
  }

  for(i=0 ; i<n ; i++){

    depth = getdepth(i);
    //printf("here\n");
    if(depth==0) printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, root\n", i, T[i].parent, getsibling(i), T[i].degree, depth, getheight(i));

    else if(T[i].left==-1 && T[i].right==-1) printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, leaf\n", i, T[i].parent, getsibling(i), T[i].degree, depth, getheight(i));

    else printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, internal node\n", i, T[i].parent, getsibling(i), T[i].degree, depth, getheight(i));
    /*
    //printf("here\n");
    printf("[");

    if(T[i].left != -1){
      id = T[i].left;
      printf("%d",id);

      while(id != -1){
        id = T[id].right;

        if(id != -1) printf(", %d",id);
      }
    }

    printf("]\n");
*/
  }
  return 0;
}

int getdepth(int i){//printf("in\n");
  int id = T[i].parent;
  int cnt = 0;

  while(id != -1){
    id = T[id].parent;
    cnt++;
    //printf("while\n");
  }

  return cnt;
}

int getsibling(int i){
  if(T[i].parent == -1) return -1;
  else if(T[T[i].parent].left == i) return T[T[i].parent].right;
  else return T[T[i].parent].left;
}

int getheight(int i){
  int l, r;
  if(i==-1) return -1;

  l = getheight(T[i].left);
  r = getheight(T[i].right);

  if(l>r) return l+1;
  else return r+1;

}
