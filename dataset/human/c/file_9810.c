#include<stdio.h>
#define MAX 100000
#define N -1

typedef struct node{
  int p,l,r;
}Node;

Node T[MAX];
int n,depth[MAX];

void printchild(int x){
  int t = T[x].l;
  int i=0;
  for(;t!=N;t=T[t].r){
    if(i!=0)printf(", ");
    i=1;
    printf("%d",t);
  }
}

void print(int x){
  printf("node %d: parent = %d, depth = %d, ",x,T[x].p,depth[x]);
  if(T[x].p==N)printf("root, [");
  else if(T[x].l==N)printf("leaf, [");
  else printf("internal node, [");
  printchild(x);
  printf("]\n");
}

void getdepth(int x,int y){
  depth[x]=y;
  if(T[x].r!=N)getdepth(T[x].r,y);
  if(T[x].l!=N)getdepth(T[x].l,y+1);
}

int main(){
  scanf("%d",&n);
  int i;
  for(i=0;i<n;i++)T[i].p=T[i].l=T[i].r=N;
  int j,current,num,child;
  for(i=0;i<n;i++){
    scanf("%d %d",&current,&num);
    int left;
    for(j=0;j<num;j++){
      scanf("%d",&child);
      if(j==0)T[current].l=child;
      else T[left].r=child;
      left=child;
      T[child].p=current;
  }
  }
  int r;
  for(i=0;i<n;i++)if(T[i].p==N)r=i;
  getdepth(r,0);
  for(i=0;i<n;i++)print(i);
  
  return 0;
}
