#include<stdio.h>
#define MAX 100005
#define N -1

typedef struct{ 
  int parent;
  int right,left;
}Record;
Record u[MAX];
int n,D[MAX];

void print(int s){
  int i,c;
  printf("node %d: parent = %d, depth = %d, ",s,u[s].parent,D[s]);

  if(u[s].parent == N)printf("root, ");
  else if(u[s].left == N)printf("leaf, ");
  else printf("internal node, ");
  printf("[");
  for(i=0, c=u[s].left; c!=N; i++, c = u[c].right){
    if(i>=1)printf(", ");
    printf("%d",c);
  }
  printf("]\n");

}


void depth(int s, int p){
  D[s] = p;
  if(u[s].right != N){
    depth(u[s].right,p);
  }
  if(u[s].left != N){
    depth(u[s].left,p+1);
  }
}


int main(){
  int i,j,k,l,num,node,r;

  scanf("%d",&n);
  //Record[u]内の整数を初期化（必要なぶんだけ）
  for(i=0; i<n; i++) u[i].parent = u[i].right = u[i].left = N;
  //input
  for(i=0; i<n; i++){
    scanf("%d%d",&node,&num);
    for(j=0; j<num; j++){
      scanf("%d",&k);
      if(j == 0) u[node].left = k;
      else u[l].right = k;//よくわからん
      l = k;
      u[k].parent = node;
    }
  }
  for(i=0; i<n ; i++){
    if(u[i].parent == N)r = i;
  }
  
  depth(r,0);
  for(i=0; i<n; i++)print(i);
    
  return 0;
}
