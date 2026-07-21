#include<stdio.h>
#define MAX 100000
#define N -1

typedef struct{
  int p,l,r;
}Node;

Node T[MAX];
int n,depth[MAX],height[MAX];

/*void printchild(int x){
  int t = T[x].l;
  int i=0;
  for(;t!=N;t=T[t].r){
    if(i!=0)printf(", ");
    i=1;
    printf("%d",t);
  }
}*/

int getdegree(int x){
  int n=0;
  if(T[x].l!=N)n++;
  if(T[x].r!=N)n++;
  return n;
}

int getsibling(int z){
  if(T[z].p==N)return N;
  if(T[T[z].p].l==z && T[T[z].p].r!=N)return T[T[z].p].r;
  if(T[T[z].p].r==z && T[T[z].p].l!=N)return T[T[z].p].l;
  return N;
}

void print(int x){
  printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, ",x,T[x].p,getsibling(x),getdegree(x),depth[x],height[x]);
  if(T[x].p==N)printf("root");
  else if(T[x].l==N && T[x].r==N)printf("leaf");
  else printf("internal node");
  printf("\n");
}

void getdepth(int x,int y){
  depth[x]=y;
  if(T[x].r!=N)getdepth(T[x].r,y+1);
  if(T[x].l!=N)getdepth(T[x].l,y+1);
}

int getheight(int x){
  int h1=0,h2=0;
  if(T[x].l!=N)h1=getheight(T[x].l)+1;
  if(T[x].r!=N)h2=getheight(T[x].r)+1;
  return height[x]=(h1>h2?h1:h2);
}

int main(){
  int i;
  scanf("%d",&n);
  for(i=0;i<n;i++)T[i].p=T[i].l=T[i].r=N;
  for(i=0;i<n;i++){
  int current,left,right;
  scanf("%d %d %d",&current,&left,&right);
  T[current].l=left;
  T[current].r=right;
  if(left!=N)T[left].p=current;
  if(right!=N)T[right].p=current;
}
  int r;
  for(i=0;i<n;i++)if(T[i].p==N)r=i;
  getdepth(r,0);
  getheight(r);
  for(i=0;i<n;i++)print(i);

  return 0;
}
