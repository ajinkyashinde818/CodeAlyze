#include<stdio.h>
#define M 200000
#define N 10000
#define NIL -1
struct Node{
  int p,q,c;
};
struct Node T[M];
int H[M],D[M],n;
int getheight(int);
int getsibling(int);
void getdepth(int,int);
void print(int);
int main(){
  int i,l,r,m,c,key,depth[M],j,degree=0,root;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    T[i].p=NIL;
  }
  for(i=0;i<n;i++){
    scanf("%d%d%d",&m,&l,&r);
    T[m].q=l;
    T[m].c=r;

    if(l!=NIL){
      T[l].p=m;
    }
    if(r != NIL){
      T[r].p=m;
    }
  }
  for(i=0;i<n;i++){
    if(T[i].p==NIL){
      root=i;
      break;
    }
  }
  getdepth(root,0);
  getheight(root);
  for(i=0;i<n;i++){
    print(i);
  }
  return 0;
}



int getheight(int n){
  int h1=0,h2=0;
  if(T[n].q!=NIL){
    h1=getheight(T[n].q)+1;
  }
  if(T[n].c!=NIL){
    h2=getheight(T[n].c)+1;
  }
  return H[n]=(h1>h2?h1:h2);
}

int getsibling(int n){
  if(T[n].p==NIL) return NIL;
  if(T[T[n].p].q!=n && T[T[n].p].q!=NIL){
    return T[T[n].p].q;
  }
  if(T[T[n].p].c!=n && T[T[n].p].c!=NIL){
    return T[T[n].p].c;
  }
  return NIL;
}

void getdepth(int u,int d){
  if(u == NIL)
    return;
  D[u]=d;
  getdepth(T[u].q,d+1);
  getdepth(T[u].c,d+1);
}


void print(int u){
  int deg=0;
  printf("node %d: ",u);
  printf("parent = %d, ",T[u].p);
  printf("sibling = %d, ",getsibling(u));
  if(T[u].q != NIL)
    deg++;
  if(T[u].c != NIL)
    deg++;
  printf("degree = %d, ",deg);
  printf("depth = %d, ",D[u]);
  printf("height = %d, ",H[u]);

  if(T[u].p == NIL)
    printf("root\n");
  else if(T[u].q == NIL && T[u].c == NIL)
    printf("leaf\n");
  else
    printf("internal node\n");
}
