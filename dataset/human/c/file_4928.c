#include<stdio.h>

#define MAX 100
#define NIL -1

struct node{
  int p;
  int l;
  int r;
  int s;
};

struct node Tree[MAX];
int D[MAX];

int SetH(int);
int SetD(int);

int main(){
  int i,l,n,r;
  int id;

  scanf("%d", &n);

  for(i = 0; i < n ; i++){
    Tree[i].p = Tree[i].l = Tree[i].r = Tree[i].s = NIL;
    D[i] = 0;
  }

  for(i = 0 ; i < n; i++){
    scanf("%d%d%d", &id, &l, &r);

    Tree[id].l = l;
    Tree[id].r = r;

    Tree[l].p = id;
    Tree[r].p = id;

    Tree[l].s = r;
    Tree[r].s = l;
    if(l != NIL){
      D[id]++;
    }

    if(r!=NIL){
      D[id]++;
    }
}



for(i = 0; i < n ; i++){
  printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, " , i, Tree[i].p, Tree[i].s, D[i], SetD(i), SetH(i));

  if(Tree[i].p == NIL){
    printf("root\n");
  }
  else if(D[i] > 0){
    printf("internal node\n");
  }
  else{
    printf("leaf\n");
  }
}

return 0;
}

int SetH(int u){
  int h1=0, h2=0;

  if(Tree[u].r != NIL)
  h1 = SetH(Tree[u].r) + 1;
  if(Tree[u].l != NIL)
    h2 = SetH(Tree[u].l) + 1;

  return (h1 > h2) ? h1 : h2;
}

int SetD(int u){
  int dpt=0;
  int par=Tree[u].p;

  while(par != NIL){
  dpt++;
  par = Tree[par].p;
  }

  return dpt;
}
