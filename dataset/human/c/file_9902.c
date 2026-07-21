#include<stdio.h>
#define MAX 100001
#define NIL -1
typedef struct{
  int parent;
  int left;
  int right;
}node;
void setdepth(int,int);
int getdepth(int);
void printchildren(int);
void print(int);

int n,D[MAX];
node T[MAX];

int main(){
  int k,i,j,c,p,l,num;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    T[i].parent=NIL;
    T[i].left=NIL;
    T[i].right=NIL;
  }
  for(i=0;i<n;i++){
    scanf("%d",&num);
    scanf("%d",&k);
    for(j=0;j<k;j++){
      scanf("%d",&p);
      if(j==0)T[num].left=p;
      else T[l].right=p;
      l=p;
      T[p].parent=num;
    }
  }
  for(i=0;i<n;i++){
  D[i]=getdepth(i);
}
    for(i=0;i<n;i++){
     print(i);
    }
  return 0;
}

/*void setdepth(int u,int p){
  D[u]=p;
  if(T[u].right!=NIL)setdepth(T[u].right,p);
  if(T[u].left!=NIL)setdepth(T[u].left,p+1);

}*/
int getdepth(int u){
  int d=0;
  while(T[u].parent!=NIL){
    u=T[u].parent;
    d++;
  }
  return d;
}

void printchildren(int u){
  int c,x=0;
  c=T[u].left;
  printf(" [");
  while(c!=NIL){
    if(x!=0)printf(", ");
    printf("%d",c);
    c = T[c].right;
    x=1;
  }
  printf("]\n");
}
void print(int u){
  printf("node %d: parent = %d, depth = %d,",u,T[u].parent,D[u]);

  if(T[u].parent==NIL)printf(" root,");
  else if(T[u].left==NIL)printf(" leaf,");
  else printf(" internal node,");

  printchildren(u);
}
