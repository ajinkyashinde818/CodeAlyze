#include<stdio.h>
#define  N 10000
int Height(int);
void print(int);
int Sibling(int);
void Depth(int,int);
struct Node{
  int parent;
  int left;
  int right;
};
struct Node T[N];
int n,D[N],H[N];

int main(){
  int p,l,r,root=0,i;
  scanf("%d",&n);
  for(i=0;i<n;i++)
    T[i].parent=-1;
  for(i=0;i<n;i++){
    scanf("%d%d%d",&p,&l,&r);
    T[p].left=l;
    T[p].right=r;
    if(l!=-1)T[l].parent=p;
    if(r!=-1)T[r].parent=p;
  }
  for(i=0;i<n;i++)
    if(T[i].parent==-1)
      root=i;
  Depth(root,0);
  Height(root);
  
  for(i=0;i<n;i++)
    print(i);
  return 0;
}

int Sibling(int a){
  if(T[a].parent==-1)return -1;
  if(T[T[a].parent].left !=a && T[T[a].parent].left != -1)
    return T[T[a].parent].left;
  if(T[T[a].parent].right !=a && T[T[a].parent].right != -1)
    return T[T[a].parent].right;
  return -1;
}

void Depth(int a,int b){
  if(a==-1) return;
  D[a]=b;
  Depth(T[a].left,b+1);
  Depth(T[a].right,b+1);
}

int Height(int a){
  int h1=0,h2=0;
  if(T[a].left!=-1)
    h1=Height(T[a].left)+1;
  if(T[a].right!=-1)
    h2=Height(T[a].right)+1;
  return H[a]=(h1>h2?h1:h2);
}

void print(int a){
  int d=0;
  printf("node %d:",a);
  printf(" parent = %d,",T[a].parent);
  printf(" sibling = %d,",Sibling(a));
  if(T[a].left!=-1) d++;
  if(T[a].right!=-1) d++;
  printf(" degree = %d,",d);
  printf(" depth = %d,",D[a]);
  printf(" height = %d,",H[a]);
  if(T[a].parent==-1){
    printf(" root");
  }
  else if(T[a].left==-1 && T[a].right==-1){
    printf(" leaf");
  }
  else printf(" internal node");
  printf("\n");
}
