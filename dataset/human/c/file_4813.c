#include <stdio.h>

#define NIL -1

struct Node{
  int p;
  int l;
  int r;
};

struct Node t[100005];
int n,D[100005];

int rec(int u,int p){
  D[u] = p;
  if(t[u].r != NIL)rec(t[u].r,p+1);
  if(t[u].l != NIL)rec(t[u].l,p+1);
}
int hei(int u){
  int h1=0,h2=0;

  if(t[u].r != NIL)
    h1=hei(t[u].r)+1;
  if(t[u].l != NIL)
    h2=hei(t[u].l)+1;

  if(h1>h2)return h1;
  else return h2;
}

int main(){

  int i,n,v,r,sib,deg;
  scanf("%d",&n);

  for(i=0;i<n;i++)t[i].p=t[i].l=t[i].r = NIL;
    
  for(i=0;i<n;i++){
    scanf("%d",&v);
    scanf("%d",&t[v].l);
    scanf("%d",&t[v].r);
    t[t[v].l].p = t[t[v].r].p = v;
    // printf("%d %d %d\n",t[v].l,t[v].r,t[v].p);
  }
  
  for(i=0;i<n;i++)if(t[i].p==NIL)r=i;

  rec(r,0);
  
  for(i=0;i<n;i++){
    deg=0;

    if(t[i].p==NIL)sib=-1;
    else sib = t[t[i].p].l+t[t[i].p].r-i;
    
    if(t[i].l!=NIL)deg++;
    if(t[i].r!=NIL)deg++;
    
    printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, ",i,t[i].p,sib,deg,D[i],hei(i));
  
    if(t[i].p==NIL)printf("root");
    else if(t[i].l==NIL && t[i].r==NIL)printf("leaf");
    else printf("internal node");
 
    printf("\n");

  }

 
  return 0;
}
