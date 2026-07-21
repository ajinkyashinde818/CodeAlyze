#include<stdio.h>
#define MAX 100000
 
typedef struct{
  int p,l,r;
}Node;

Node T[MAX];
int n,D[MAX],H[MAX];
 
void print(int u){
  int i,c,deg=0;
  printf("node %d: ",u);
  printf("parent = %d, ",T[u].p);
  printf("sibling = %d, ",getSibling(u));
  if(T[u].l!=-1)deg++;
  if(T[u].r!=-1)deg++;
  printf("degree = %d, ",deg);
  printf("depth = %d, ",D[u]);
  printf("height = %d, ",H[u]);
 
  if(T[u].p == -1)printf("root\n");

  else if(T[u].l == -1 && T[u].r == -1)printf("leaf\n");

  else printf("internal node\n");
 
}
 
int setHeight(int u){
  int h1=0,h2=0;
  if(T[u].l!=-1)
    h1=setHeight(T[u].l) + 1;
  if(T[u].r!=-1)
    h2=setHeight(T[u].r) + 1;
  return H[u] = (h1 > h2 ? h1 : h2);
}
 
int getSibling(int u){
  if(T[u].p == -1)return -1;
  
  if(T[T[u].p].l != u && T[T[u].p].l != -1)
    return T[T[u].p].l;
  
  if(T[T[u].p].r != u && T[T[u].p].r != -1)
    return T[T[u].p].r;
  return -1;
}
 
void rec(int u,int d){
  if(u==-1)return;
  D[u] = d;
  rec(T[u].r, d+1);
  rec(T[u].l, d+1);
}

int main(){
  int i,v,a,b,root=0;
  scanf("%d",&n);
  
  for(i=0;i<n;i++)T[i].p=-1;
  for(i=0;i<n;i++){
    scanf("%d %d %d",&v,&a,&b);
    T[v].l=a;
  T[v].r=b;
  if(a!=-1)T[a].p=v;
  if(b!=-1)T[b].p=v;
  }
  for(i=0;i<n;i++)if(T[i].p==-1)root=i;
 
  rec(root,0);
  setHeight(root);
 
  for(i=0;i<n;i++)print(i);
 
  return 0;
}
