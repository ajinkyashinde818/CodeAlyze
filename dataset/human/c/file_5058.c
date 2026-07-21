#include <stdio.h>
#include <stdlib.h>

#define Max 100000
#define N -1

struct node{
  int l;
  int r;
  int p;
};

 struct node type[Max];
 int D[Max],H[Max];

void setDepth(int u, int d){
  if(u== N) return;
    D[u]=d;
    
    setDepth(type[u].l,d+1);

    
    setDepth(type[u].r,d+1);

}


int setHeight(int u){
  int h1=0,  h2=0;
  if(type[u].l!= N){
    h1=setHeight(type[u].l)+1;
  }

  if(type[u].r!= N) {h2=setHeight(type[u].r)+1;

  }
  return H[u]=(h1>h2? h1:h2);
}

int getSibling(int u){
  if(type[u].p == N){
    return N;}
  
  if(type[type[u].p].l != u && type[type[u].p].l != N)
    {return type[type[u].p].l;
    }
  
  if(type[type[u].p].r != u && type[type[u].p].r != N)
    {
      return type[type[u].p].r; }
  return N;
}

void print(int u){
  printf("node %d: ",u);
  
  printf("parent = %d, ",type[u].p);
  
  printf("sibling = %d, ",getSibling(u));
  int deg=0;
  if(type[u].l!=N) deg++;

  
  if(type[u].r!=N) deg++;
  printf("degree = %d, ",deg);
  printf("depth = %d, ",D[u]);
  
  printf("height = %d, ",H[u]);
  

  if(type[u].p==N){
    printf("root\n");
  }
  
  else if(type[u].l == N && type[u].r == N){
    printf("leaf\n");
  }
  else printf("internal node\n");
  }


int main(){
  int v,l,r,i,n;
  int root=0;
  
  scanf("%d",&n);

  for(i=0;i<n;i++) type[i].p = N;

  for(i=0;i<n;i++){
    scanf("%d%d%d",&v,&l,&r);
    type[v].l=l;
    
    type[v].r=r;
    
    if(l != N) {type[l].p=v;
    }
    
    if(r != N) {
      type[r].p=v;}
  }

  for(i=0;i<n;i++) if(type[i].p == N) root = i;

  setDepth(root,0);
  
  setHeight(root);

  for(i=0;i<n;i++) print(i);

  return 0;
}
