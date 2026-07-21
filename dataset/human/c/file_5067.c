#include<stdio.h>
#define NIL -1
#define MAX 100000
struct Node{
  int p;
  int l1;
  int r1;
};

struct Node T[MAX];
int depth[MAX],height[MAX];
void setDepth(int u, int d){
  if(u==NIL)return;
  depth[u]=d;
  setDepth(T[u].l1,d+1);
  setDepth(T[u].r1,d+1);
}

int setHeight(int u){
  int h1=0,h2=0;
  if(T[u].l1!=NIL)h1=setHeight(T[u].l1)+1;
  if(T[u].r1!=NIL)h2=setHeight(T[u].r1)+1;
  return height[u]=(h1>h2 ? h1 : h2);
}

int getSibling(int u){
  if(T[u].p==NIL)return NIL;
  if(T[T[u].p].l1 != u && T[T[u].p].l1!=NIL)
    return T[T[u].p].l1;
  if(T[T[u].p].r1 != u && T[T[u].p].r1!=NIL)
     return T[T[u].p].r1;
   else return NIL;
}

 void print(int u){
   int k,m,deg=0; 
  printf("node %d: ", u);
  printf("parent = %d, ", T[u].p);
  k=getSibling(u);
  printf("sibling = %d, ", k);
  if(T[u].l1!=NIL)deg++;
  if(T[u].r1!=NIL)deg++;
  printf("degree = %d, ", deg);
  printf("depth = %d, ", depth[u]);
  printf("height = %d, ", height[u]);

  if(T[u].p==NIL)printf("root\n");
  else if(T[u].l1==NIL && T[u].r1==NIL)printf("leaf\n");
  else printf("internal node\n");
}


int main(){
  int i,n,id,l2,r2,root=0;
  scanf("%d", &n);
  for(i=0;i<n;i++)T[i].p=NIL;
  
  for(i=0;i<n;i++){
    scanf("%d %d %d", &id, &l2, &r2);
    T[id].l1=l2;
    T[id].r1=r2;
    if(l2!=NIL)T[l2].p=id;
    if(r2!=NIL)T[r2].p=id;
  }
  
  for(i=0;i<n;i++){
    if(T[i].p==NIL)root=i;}
    setDepth(root,0);
    setHeight(root);
    for(i=0;i<n;i++){print(i);}
    
  return 0;
}
