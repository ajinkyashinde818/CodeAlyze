#include<stdio.h>

#define MAX 10000
#define NIL -1


struct Node{
  int parent,left,right;
};

struct Node A[MAX];
int n,B[MAX],C[MAX];

void dep(int s,int t){
  if(s == NIL) return;
  B[s] = t;
  dep(A[s].left,t+1);
  dep(A[s].right,t+1);
}

int he(int s){
  int he1=0,he2 = 0;
  if(A[s].left !=NIL)
    he1 = he(A[s].left) +1;
  if(A[s].right!=NIL)
    he2 = he(A[s].right) +1;
  return C[s] = (he1>he2?he1:he2);
}

int sib(int s){
  if(A[s].parent == NIL)return NIL;
  if(A[A[s].parent].left != s&&A[A[s].parent].left!=NIL)
    return A[A[s].parent].left;
   if(A[A[s].parent].right != s&&A[A[s].parent].right!=NIL)
     return A[A[s].parent].right;
   return NIL;
}

void pr(int s){
  printf("node %d: ",s);
  printf("parent = %d, ",A[s].parent);
  printf("sibling = %d, ",sib(s));
  int deg = 0;
  if(A[s].left!=NIL)deg++;
  if(A[s].right!= NIL)deg++;
  printf("degree = %d, ",deg);
  printf("depth = %d, ",B[s]);
  printf("height = %d, ",C[s]);

  if(A[s].parent ==NIL){
    printf("root\n");
  }else if(A[s].left == NIL&&A[s].right == NIL){
    printf("leaf\n");
  }else {
    printf("internal node\n");
  }
}


int main(){

  int l,r,root = 0,w,i;
  scanf("%d",&n);

  for(i = 0;i<n;i++)A[i].parent = NIL;

  for(i = 0;i<n;i++) {
    scanf("%d %d %d",&w,&l,&r);
    A[w].left = l;
    A[w].right = r;
    if(l!=NIL) A[l].parent = w;
    if(r != NIL)A[r].parent = w;
  }

  for(i = 0;i<n;i++)
    if(A[i].parent == NIL)root = i;

  dep(root,0);
  he(root);

  for(i = 0;i<n;i++)
    pr(i);

  return 0;
  

}
