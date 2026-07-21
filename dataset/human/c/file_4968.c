#include<stdio.h>

#define max 10000
#define nil -1

typedef struct Node{
  int p, l, r;
} node;

node t[max];

int n, d[max], h[max];

void dep(int u, int D){
  if(u==nil)return;
  d[u]=D;
  dep(t[u].l, D+1);
  dep(t[u].r, D+1);
}

int hei(int u){
  int h1=0, h2=0;
  if(t[u].l!=nil)h1=hei(t[u].l)+1;
  if(t[u].r!=nil)h2=hei(t[u].r)+1;

  if(h1<h2)h[u]=h2;
  else h[u]=h1;
  return h[u];
}

int sib(int u){
  if(t[u].p==nil)return nil;
  if(t[t[u].p].l!=u && t[t[u].p].l!=nil)return t[t[u].p].l;
  if(t[t[u].p].r!=u && t[t[u].p].r!=nil)return t[t[u].p].r;
  return nil;
}

void Pr(int u){
  int deg=0;
  printf("node %d: ", u);
  printf("parent = %d, ", t[u].p);
  printf("sibling = %d, ", sib(u));
  if(t[u].l!=nil)deg++;
  if(t[u].r!=nil)deg++;
  printf("degree = %d, ", deg);
  printf("depth = %d, ", d[u]);
  printf("height = %d, ", h[u]);
  if(t[u].p==nil){
    printf("root\n");
  }else if(t[u].l==nil && t[u].r==nil){
    printf("leaf\n");
  }else {
    printf("internal node\n");
  }
}

int main(){
  int v, l, r, root=0, i;
  scanf("%d", &n);
  for(i=0 ; i<n ; i++)t[i].p=nil;
  for(i=0 ; i<n ; i++){
    scanf("%d%d%d",&v, &l, &r);
    t[v].l=l;
    t[v].r=r;
    if(l!=nil)t[l].p=v;
    if(r!=nil)t[r].p=v;
  }
  for(i=0 ; i<n ; i++)if(t[i].p==nil)root=i;
  dep(root, 0);
  hei(root);
  for(i=0 ; i<n ; i++)Pr(i);
  return 0;
}
