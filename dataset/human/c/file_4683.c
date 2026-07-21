#include<stdio.h>

#define MAX 100000
#define NIL -1

struct Type{ 
  int p, l, r;
};
struct Type A[MAX];

int n,D[MAX];

int getDegree(int u){
  if(A[u].l!=NIL && A[u].r!=NIL) return 2;
  else if(A[u].l==NIL && A[u].r==NIL) return 0;
  else return 1;
}
 
int getDepth(int u){
  int d=0;
  while(A[u].p!=NIL){
    u=A[u].p;
    d++;
  }
  return d;
}


int getHeight(int u,int count){
  int height1=0,height2=0;
  count++;
  if(A[u].l!=NIL){
    height1=getHeight(A[u].l,count);
  }
  if(A[u].r!=NIL){
    height2=getHeight(A[u].r,count);
  }
  if(A[u].l==NIL && A[u].r==NIL){
    return count;
  }
  if(height1<height2)return height2;
  else return height1;
}

int getSibling(int u){
  int p;
  if(A[u].p==NIL)return -1;
  p=A[u].p;
  if(A[p].l==u)return A[p].r;
  if(A[p].r==u)return A[p].l;
}

void print(int u){
  int i;
  printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, ",u,A[u].p,getSibling(u),getDegree(u),D[u],getHeight(u,-1));
  if(A[u].p==NIL)printf("root\n");
  else if(A[u].l==NIL && A[u].r==NIL) printf("leaf\n");
  else if(A[u].l!=NIL || A[u].r!=NIL )printf("internal node\n");
}

main(){
  int i, j,v,l,r;
  scanf("%d", &n);
  for(i=0;i<n;i++) {
    A[i].p=NIL;
    A[i].l=NIL;
    A[i].r=NIL;
  }
  for(i=0;i<n;i++){
    scanf("%d %d %d",&v,&l,&r);
    A[v].l=l;
    A[v].r=r;
    A[l].p=v;
    A[r].p=v;
  }
  for(i=0;i<n;i++){
    D[i]=getDepth(i);
  }
  for(i=0;i<n;i++) print(i);
  return 0;
}
