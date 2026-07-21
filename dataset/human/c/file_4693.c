#include <stdio.h>
#define M 100000
#define N -1

struct Node{
int parent,left,right;
};
struct Node T[M];
int D[M],H[M];

void setdepth(int u,int d){
  if(u==N)return;
  D[u]=d;
  setdepth(T[u].left,d+1);
  setdepth(T[u].right,d+1);
}

int setheight(int u){
  int h1=0,h2=0;
  if(T[u].left != N)
    h1=setheight(T[u].left)+1;
  if(T[u].right != N)
    h2=setheight(T[u].right)+1;
  if(h1>h2) return H[u]=h1;
  else return H[u]=h2;
}

int getsibling(int u){
  if(T[u].parent==N)return N;
  if(T[T[u].parent].left != u && T[T[u].parent].left != N)
    return T[T[u].parent].left;
  if(T[T[u].parent].right != u && T[T[u].parent].right != N)
    return T[T[u].parent].right;
  else return N;
}

void print(int u){
  int cnt=0;
  printf("node %d: ",u);
  printf("parent = %d, ",T[u].parent);
  printf("sibling = %d, ",getsibling(u));
  if(T[u].left!=N) cnt++;
  if(T[u].right!=N) cnt++;
  printf("degree = %d, ",cnt);
  printf("depth = %d, ",D[u]);
  printf("height = %d, ",H[u]);

  if(T[u].parent == N){
    printf("root\n");
  }else if(T[u].left == N && T[u].right == N){
    printf("leaf\n");
  }else{
    printf("internal node\n");
      }
}

int main(){
  int n,i,k,t,y,root;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    T[i].parent=N;
  }

  for(i=0;i<n;i++){
    scanf("%d %d %d",&k,&t,&y);
    T[k].left=t;
    T[k].right=y;
    if(t!=N)T[t].parent=k;
    if(y!=N)T[y].parent=k;
  }
  for(i=0;i<n;i++){
    if(T[i].parent == N) root=i;
  }
  setdepth(root,0);
  setheight(root);

  for(i=0;i<n;i++){
    print(i);
  }

  return 0;
}
