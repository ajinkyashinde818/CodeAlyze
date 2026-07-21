#include<stdio.h>

#define MAX 100
#define NIL -1

struct node{
  int parent;
  int left;
  int right;
  int sib;
};

struct node T[MAX];
int Deg[MAX];

int setD(int);
int setH(int);

int main(){
  int n;
  int id, l, r;
  int i;

  scanf("%d", &n);

  for(i=0; i<n; i++){
    T[i].parent = T[i].left = T[i].right = T[i].sib = NIL;
    Deg[i] = 0;
  }

  for(i=0; i<n; i++){
    scanf("%d%d%d", &id, &l, &r);

    T[id].left = l;
    T[id].right = r;
    
    T[l].parent = id;
    T[r].parent = id;

    T[l].sib = r;
    T[r].sib = l;

    if(l!=NIL)
      Deg[id]++;

    if(r!=NIL)
      Deg[id]++;
  }

  

  for(i=0; i<n; i++){
    printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, "
	   , i, T[i].parent, T[i].sib, Deg[i], setD(i), setH(i));

    if(T[i].parent == NIL)
      printf("root\n");

    else if(Deg[i]>0)
      printf("internal node\n");

    else
      printf("leaf\n");
  }
  
  return 0;
}

int setD(int u){
  int dpt=0;
  int par = T[u].parent;
  
  while(par != NIL){
    dpt++;
    par = T[par].parent;
  }

  return dpt;
}

int setH(int u){
  int h1=0, h2=0;

  if(T[u].right != NIL)
    h1 = setH(T[u].right) + 1;
  if(T[u].left != NIL)
    h2 = setH(T[u].left) + 1;

  return (h1>h2) ? h1 : h2;
}
