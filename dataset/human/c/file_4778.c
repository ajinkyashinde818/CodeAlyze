#include <stdio.h>
#define MAX 10000
#define NIL -1

struct Node{
  int p,l,r;
};

struct Node t[MAX];
int n,d[MAX],h[MAX];

void depth(int u, int de){
  if(u==NIL)return;
  d[u]=de;
  depth(t[u].l,de+1);
  depth(t[u].r,de+1);
}

int high(int u){
  int h1=0,h2=0;
  if(t[u].l!=NIL)h1=high(t[u].l)+1;
  if(t[u].r!=NIL)h2=high(t[u].r)+1;
  return h[u]=(h1>h2 ? h1 : h2);
}

int sibling(int u){
  if(t[u].p==NIL)return NIL;
  if(t[t[u].p].l!=u && t[t[u].p].l!=NIL)return t[t[u].p].l;
  if(t[t[u].p].r!=u && t[t[u].p].r!=NIL)return t[t[u].p].r;
  return NIL;
}

void print(int u){
  printf("node %d: ",u);
  printf("parent = %d, ",t[u].p);
  printf("sibling = %d, ",sibling(u));
  int degree;
  if(t[u].l!=NIL)degree++;
  if(t[u].r!=NIL)degree++;
  printf("degree = %d, ",degree);
  printf("depth = %d, ",d[u]);
  printf("height = %d, ",h[u]);

  if(t[u].p==NIL)printf("root\n");
  else if(t[u].l==NIL && t[u].r==NIL)printf("leaf\n");
  else printf("internal node\n");
  
  }

int main(){
  int v,l,r,root=0,i;
  scanf("%d",&n);

  for(i=0;i<n;i++)t[i].p=NIL;

  for(i=0;i<n;i++){
    scanf("%d%d%d",&v,&l,&r);
    t[v].l=l;
    t[v].r=r;
    if(l!=NIL)t[l].p=v;
    if(r!=NIL)t[r].p=v;
    
  }

  for(i=0;i<n;i++)if(t[i].p==NIL)root=i;

  depth(root,0);
  high(root);

  for(i=0;i<n;i++)print(i);
  return 0;
}
