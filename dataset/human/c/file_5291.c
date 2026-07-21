#include<stdio.h>
#define MAX 10000
#define NIL -1
struct node{
  int p,lc,rs;
};
struct node T[MAX];
int n,D[MAX],h[MAX];
void deep(int,int);void print(int);
int height(int);int culc(int);
int main(){
  int l,r,z=0,a,i;
  scanf("%d",&n);
  for(i=0;i<n;i++)T[i].p=NIL;
  for(i=0;i<n;i++){
    scanf("%d%d%d",&a,&l,&r);
    T[a].lc=l;T[a].rs=r;
    if(l!=NIL)T[l].p=a;
    if(r!=NIL)T[r].p=a;
  }
  for(i=0;i<n;i++){
    if(T[i].p==NIL)z=i;
  }
  deep(z,0);height(z);
  for(i=0;i<n;i++)print(i);
  return 0;
}

void deep(int p,int q){
  if(p==NIL)return 0;
  D[p]=q;
  deep(T[p].lc,q+1);deep(T[p].rs,q+1);
}
int height(int x){
  int h1=0,h2=0;
  if(T[x].lc!=NIL)h1=height(T[x].lc)+1;
  if(T[x].rs!=NIL)h2=height(T[x].rs)+1;
  return h[x]=(h1>h2?h1:h2);
}

int culc(int u){
  if(T[u].p==NIL) return NIL;
  if(T[T[u].p].lc!=u&&T[T[u].p].lc!=NIL)return T[T[u].p].lc;
  if(T[T[u].p].rs!=u&&T[T[u].p].rs!=NIL)return T[T[u].p].rs;
  return NIL;
  
}

void print(int z){
  int cnt=0;
  printf("node %d:",z);
  printf(" parent = %d,",T[z].p);
  printf(" sibling = %d,",culc(z));
  if(T[z].lc!=NIL)cnt++; if(T[z].rs!=NIL)cnt++;
  printf(" degree = %d,",cnt);
  printf(" depth = %d,",D[z]);
  printf(" height = %d,",h[z]);
  if(T[z].p==NIL)printf(" root\n");
  else if(T[z].lc==NIL&&T[z].rs==NIL)printf(" leaf\n");
  else printf(" internal node\n");
}
