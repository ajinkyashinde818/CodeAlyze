#include<stdio.h>
#include<stdlib.h>
#define MAX 10000
#define NIL -1

struct node{
  int parent,left,right;

};
struct node T[MAX];
int D[MAX],n,H[MAX];

void depth(int,int);
int height(int);
int get(int);
void print(int);


int main(){
  int i,id,l,r,rt=0;

  scanf("%d",&n);
  if(n<1||n>25) exit(1);

  for(i=0;i<n;i++)
    T[i].parent=NIL;
  for(i=0;i<n;i++){
    scanf("%d%d%d",&id,&l,&r);
    T[id].left=l;
    T[id].right=r;
    if(l!=NIL) T[l].parent=id;
    if(r!=NIL) T[r].parent=id;

  }
  for(i=0;i<n;i++)
    if(T[i].parent == NIL) rt=i;
  depth(rt,0);
  height(rt);

  for(i=0;i<n;i++) print(i);
  return 0;
}

void depth(int u,int dep){
  if(u == NIL) return;
  D[u] = dep;
  depth(T[u].left,dep+1);
  depth(T[u].right,dep+1);

}

int height(int u){
  int hl=0,hr=0;
  if(T[u].left!=NIL)
    hl= height(T[u].left)+1;
  if(T[u].right!=NIL)
    hr= height(T[u].right)+1;

  if(hl>hr) H[u]=hl;
  else H[u]=hr;
  return H[u];
}

int get(int u){


  if(T[u].parent==NIL) return NIL;
  if(T[T[u].parent].left != u&&T[T[u].parent].left !=NIL)
    return T[T[u].parent].left;
  if(T[T[u].parent].right != u&&T[T[u].parent].right !=NIL)
    return T[T[u].parent].right;
  return NIL;


}

void print(int u){
  int d;
  printf("node %d: ",u);
  printf("parent = %d, ",T[u].parent);
  printf("sibling = %d, ",get(u));
  d=0;
  if(T[u].left!=NIL) d++;
  if(T[u].right!=NIL) d++;
  printf("degree = %d, ",d);
  printf("depth = %d, ",D[u]);
  printf("height = %d, ",H[u]);

  if(T[u].parent==NIL){
    printf("root\n");

  }else if(T[u].left ==NIL&&T[u].right==NIL){
    printf("leaf\n");
  }else{
    printf("internal node\n");

  }
	 
}
