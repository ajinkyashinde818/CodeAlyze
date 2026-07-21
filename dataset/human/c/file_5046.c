#include<stdio.h>
#define MAX 100005
#define N -1

typedef struct{ 
  int parent;
  int right,left;
}Record;
Record u[MAX];
int n,D[MAX],H[MAX];


void depth(int s, int p){
  if(s == N)return;
  D[s] = p;
  depth(u[s].left,p+1);
  depth(u[s].right,p+1);
}


int height(int s){
  int h1 = 0,h2 = 0;
  if(u[s].left != N){
    h1 = height(u[s].left) + 1;
  }
  if(u[s].right != N){
    h2 = height(u[s].right) + 1;
  }
  if(h1 > h2)H[s] = h1;
  else H[s] = h2;
  return H[s]; 
}


int Sibling(int s){
  if(u[s].parent == N)return N;

  if(u[u[s].parent].left != s && u[u[s].parent].left !=N){
    return u[u[s].parent].left;
  }
  if(u[u[s].parent].right != s && u[u[s].parent].right !=N){
    return u[u[s].parent].right;
  }
  return N;
}


void print(int s){
  int i,c;
  
  printf("node %d: ",s);
  printf("parent = %d, ",u[s].parent);
  printf("sibling = %d, ",Sibling(s));
  
  i = 0;
  if(u[s].left != N)i++;
  if(u[s].right != N)i++;
  printf("degree = %d, ",i);
  printf("depth = %d, ",D[s]);
  printf("height = %d, ",H[s]);
  
  if(u[s].parent == N)printf("root\n");
  else if(u[s].left == N && u[s].right ==N)printf("leaf\n");
  else printf("internal node\n");
}


int main(){
  int i,j,l,num,node,r,root=0;

  scanf("%d",&n);
  //Record[u]内の整数を初期化（必要なぶんだけ）
  for(i=0; i<n; i++) u[i].parent= N;
  //input
  for(i=0; i<n; i++){
    scanf("%d",&node);
    scanf("%d %d",&l,&r);
    u[node].left = l;
    u[node].right = r;
    if(l != N) u[l].parent = node;
    if(r != N) u[r].parent = node;
  }
  for(i=0; i<n ; i++){
    if(u[i].parent == N)root = i;//rootを見つけるため
  }
  
  depth(root,0);
  height(root);
  
  for(i=0; i<n; i++)print(i);
    
  return 0;
}
