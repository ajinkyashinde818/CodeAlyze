#include<stdio.h>
#define MAX 25

void depth(int, int);
int height(int);
int sibling(int);

typedef struct{
  int p;
  int l; //left
  int r; //right
}Tree;
Tree A[MAX];

int n,B[10000],C[10000];

int main(){
  int root,deg;
  int id,l,r;
  int i,j;
  int N;

  scanf("%d",&N);
  for(i=0;i<N;i++) A[i].p=-1;

  for(i=0;i<N;i++){
    scanf("%d%d%d",&id,&l,&r);
    A[id].l=l;
    A[id].r=r;
    if(l!=-1) A[l].p=id;
    if(r!=-1) A[r].p=id;
  }
  for(i=0;i<N;i++){
    if(A[i].p==-1) root=i;
  }

  depth(root,0);
  height(root);

  for(i=0; i<N; i++){
    printf("node %d: ", i);
    printf("parent = %d, ", A[i].p);
    printf("sibling = %d, ",sibling(i));
    deg=0;
    if(A[i].l!=-1) deg++;
    if(A[i].r!=-1) deg++;
    printf("degree = %d, ", deg);
    printf("depth = %d, ", B[i]);
    printf("height = %d, ", C[i]);

    if(A[i].p==-1) printf("root\n");
    else if(A[i].l==-1 && A[i].r==-1) printf("leaf\n");
    else printf("internal node\n");
  }
  
  return 0;
}

void depth(int i, int j){
  if(i==-1) return;
  B[i]=j;
  depth(A[i].l,j+1);
  depth(A[i].r,j+1);
}

int height(int i){
  int a1=0,a2=0;
  if(A[i].l!=-1) a1=height(A[i].l) +1;
  if(A[i].r!=-1) a2=height(A[i].r) +1;
  return C[i]=(a1>a2 ? a1:a2);
}

int sibling(int i){
  if(A[i].p == -1) return -1;
  if(A[A[i].p].l!=i && A[A[i].p].l!=-1) return A[A[i].p].l;
  if(A[A[i].p].r!=i && A[A[i].p].r!=-1) return A[A[i].p].r;
  return -1;
}
