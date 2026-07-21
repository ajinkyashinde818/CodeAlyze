#include <stdio.h>
#define MAX 25
#define N -1
struct Node{int p, l, r;};
struct Node T[MAX];

int n, D[MAX],H[MAX];
void setDepth(int x,int d){
  if(x==N)
    return;
  D[x]=d;
  setDepth(T[x].l,d+1);
  setDepth(T[x].r,d+1);
}

int setHeight(int x){
  int h1=0,h2=0;
  if(T[x].l!=N)
    h1=setHeight(T[x].l)+1;
  if(T[x].r!=N)
    h2=setHeight(T[x].r)+1;
  return H[x]=(h1 > h2 ? h1 : h2);
}

int getSibling(int x){
  if(T[x].p==N)
    return N;
  if(T[T[x].p].l!=x&&T[T[x].p].l!=N)
    return T[T[x].p].l;
  if(T[T[x].p].r!=x&&T[T[x].p].r!=N)
    return T[T[x].p].r;
  return N;
}

void print(int x){
  printf("node %d: ",x);
  printf("parent = %d, ",T[x].p);
  printf("sibling = %d, ",getSibling(x));
  int deg =0;
  if(T[x].l!=N)
    deg++;
  if(T[x].r!=N)
    deg++;
  printf("degree = %d, ",deg);
  printf("depth = %d, ",D[x]);
  printf("height = %d, ",H[x]);
  if(T[x].p==N){
    printf("root\n");
  }
  else if(T[x].l==N&&T[x].r==N){
    printf("leaf\n");
  }
  else{
    printf("internal node\n");
  }
}

int main(){
  int i,v,l,r,root=0;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    T[i].p=N;
  }
  for(i=0;i<n;i++){
    scanf("%d%d%d",&v,&l,&r);
    T[v].l=l;
    T[v].r=r;
    if(l!=N)
      T[l].p=v;
    if(r!=N)
      T[r].p=v;
  }
  for(i=0;i<n;i++){
    if(T[i].p==N){
      root=i;
    }
  }
  setDepth(root,0);
  setHeight(root);
  for(i=0;i<n;i++){
    print(i);
  }
  return 0;
}
