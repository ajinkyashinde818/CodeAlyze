#include<stdio.h>
#define MAX 100000
typedef struct{
  int p,r,l;
}Node;
Node T[MAX];
int a,d[MAX],h[MAX];

int sibling(int);
void depth(int,int);
int height(int);
void print(int);

int main(){
  int n,id,r,l,x=0;
  int i;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    T[i].p=-1;
  }
  for(i=0;i<n;i++){
    scanf("%d%d%d",&id,&l,&r);
    T[id].l=l;
    T[id].r=r;
    if(r!=-1) T[r].p=id;
    if(l!=-1) T[l].p=id;
  }
  for(i=0;i<n;i++){
    if(T[i].p==-1) x=i;
  }
  depth(x,0);
  height(x);
  for(i=0;i<n;i++){
    print(i);
  }
  return 0;
}

void depth(int a, int b){
  if(a==-1) return;
  d[a]=b;
  depth(T[a].l,b+1);
  depth(T[a].r,b+1);
}
int height(int a){
  int r=0,l=0;
  if(T[a].r!=-1) r=height(T[a].r)+1;
  if(T[a].l!=-1) l=height(T[a].l)+1;
  if(T[a].r==-1 && T[a].l==-1) return 0;
  if(l>r) return h[a]=l;
  else return h[a]=r;
}
int sibling(int a){
  if(T[a].p==-1) return -1;
  if(T[T[a].p].l!=a && T[T[a].p].l!=-1) return T[T[a].p].l;
  if(T[T[a].p].r!=a && T[T[a].p].r!=-1) return T[T[a].p].r;
  return -1;
}
void print(int a){
  int dg=0;
  printf("node %d: parent = %d,",a,T[a].p);
  printf(" sibling = %d,",sibling(a));
  if(T[a].l!=-1) dg++;
  if(T[a].r!=-1) dg++;
  printf(" degree = %d,",dg);
  printf(" depth = %d, height = %d, ",d[a],h[a]);
  if(T[a].p==-1) printf("root\n");
  else if(T[a].l==-1 && T[a].r==-1) printf("leaf\n");
  else printf("internal node\n");
}
