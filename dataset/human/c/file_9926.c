#include<stdio.h>
#include<stdlib.h>
#define NIL -1
#define MAX 100005

typedef struct{
  int p,l,r;
}Node;

int getDepth(int,Node *);
void print(int ,Node *);

int D[MAX];
  
int main(){
  Node *T;
  int n,i,j;
  int id,c,nm,l;

  scanf("%d",&n);
  T=(Node *)malloc(n*sizeof(Node));
  for(i=0;i<n;i++) T[i].p=T[i].l=T[i].r=NIL;
  for(i=0;i<n;i++){
    scanf("%d %d",&id,&nm);
    for(j=0;j<nm;j++){
      scanf("%d",&c);
      if(j==0) T[id].l=c;
      else     T[l].r=c;
      l=c;
      T[c].p=id;
    }
  }
  print(n,T);
  
  return 0;
}

int getDepth(int u,Node *T){
  int d=0;
  while(T[u].p!=NIL){
    u=T[u].p;
    d++;
  }
  return d;
}

void print(int n,Node *T){
  int i,j,c;
  
  for(i=0;i<n;i++){
    printf("node %d: parent = %d, depth = %d, ",i,T[i].p,getDepth(i,T));
    if(T[i].p==NIL)      printf("root,");
    else if(T[i].l==NIL) printf("leaf,");
    else                 printf("internal node,");
    j=i;
    printf(" [");
    for(j=0,c=T[i].l;c!=NIL;j++,c=T[c].r){
      if(j) printf(", ");
      printf("%d",c);
    }
	printf("]\n");
  }
}
