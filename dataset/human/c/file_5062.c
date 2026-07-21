#include<stdio.h>

#define N 10000
 
typedef struct{
  int p;
  int l;
  int r;
}Node;
 
Node Tr[N];
int n, D[N], A[N];


void setDepth(int u, int d){
  if(u == -1) return;
  D[u] = d;
  setDepth(Tr[u].l, d+1);
  setDepth(Tr[u].r, d+1);
}


int setHeight(int u){
  int h1=0, h2=0;
  
  if(Tr[u].l != -1){
    h1 = setHeight(Tr[u].l) + 1;
  }
  
  if(Tr[u].r != -1){
    h2 = setHeight(Tr[u].r) + 1;
  }
  
  return A[u] = (h1 > h2 ? h1 : h2);
}


int getSibling(int u){
  if(Tr[u].p == -1) return -1;
  if(Tr[Tr[u].p].l != u && Tr[Tr[u].p].l != -1) return  Tr[Tr[u].p].l;
  if(Tr[Tr[u].p].r != u && Tr[Tr[u].p].r != -1) return Tr[Tr[u].p].r;
  return -1;
}


int main(){
  int i, q, l, r, deg, root=0;
 
  scanf("%d", &n);
 
  for(i=0; i<n; i++) Tr[i].p = -1;
 
  for(i=0; i<n; i++){
    scanf("%d %d %d",&q,&l,&r);
    Tr[q].l = l;
    Tr[q].r = r;
    if(l != -1) Tr[l].p = q;
    if(r != -1) Tr[r].p = q;
  }
 
  for(i=0; i<n; i++){
    if(Tr[i].p == -1) root = i;
  }
 
  setDepth(root,0);
  setHeight(root);
 
  for(i=0; i<n; i++){
    printf("node %d: ", i);
    printf("parent = %d, ", Tr[i].p);
    printf("sibling = %d, ", getSibling(i));
    
    deg = 0;
    
    if(Tr[i].l != -1) deg++;
    if(Tr[i].r != -1) deg++;
    printf("degree = %d, ", deg);
    printf("depth = %d, ", D[i]);
    printf("height = %d, ", A[i]);
 
    if(Tr[i].p == -1){
      printf("root\n");
    }
    else if(Tr[i].l == -1 && Tr[i].r == -1){
      printf("leaf\n");
    }
    else printf("internal node\n");
  }
   
  return 0;
}
