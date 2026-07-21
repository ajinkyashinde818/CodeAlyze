#include <stdio.h>
#define max 10013
#define nil -1

typedef struct {
  int parent;
  int left;
  int right;
} nd;

nd N[max];
int n,deep[max],high[max];

void deep_cal(int u,int d){
  if(u==nil) {return;}
  deep[u]=d;
  deep_cal(N[u].left,d+1);
  deep_cal(N[u].right,d+1);
}

int high_cal(int u){
  int h1=0,h2=0;
  if (N[u].left!=nil){
    h1=high_cal(N[u].left)+1;
  }
  if(N[u].right!=nil){
    h2=high_cal(N[u].right)+1;
  }
  return high[u]=( h1 > h2 ? h1:h2);
}

int sibling_cal(int u){
  if(N[u].parent==nil){
    return nil;
  }
  if(N[N[u].parent].left!=u && N[N[u].parent].left!=nil){
    return N[N[u].parent].left;
  }
  if(N[N[u].parent].right!=u && N[N[u].parent].right!=nil){
    return N[N[u].parent].right;
  }
  return nil;
}

void print(int u){
  printf("node %d: ",u);
  printf("parent = %d, ",N[u].parent);
  printf("sibling = %d, ",sibling_cal(u));
  int deg=0;
  if(N[u].left!=nil){
    deg++;
  }
  if(N[u].right!=nil){
    deg++;
  }
  printf("degree = %d, ",deg);
  printf("depth = %d, ",deep[u]);
  printf("height = %d, ",high[u]);

  if(N[u].parent==nil){
    printf("root\n");
  }
  else if(N[u].left==nil && N[u].right==nil){
    printf("leaf\n");
  }
  else {
    printf("internal node\n");
  }
}


int main(){
  int i,v,l,r,root=0;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    N[i].parent=nil;
  }
  for(i=0;i<n;i++){
    scanf("%d %d %d",&v,&l,&r);
    N[v].left=l;
    N[v].right=r;
    if(l!=nil){
      N[l].parent=v;
    }
    if(r!=nil){
      N[r].parent=v;
    }
  }
  for(i=0;i<n;i++){
    if(N[i].parent==nil){
      root=i;
    }
  }
  deep_cal(root,0);
  high_cal(root);
  for(i=0;i<n;i++){
    print(i);
  }
  return 0;
}
