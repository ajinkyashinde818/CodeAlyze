#include<stdio.h>
#define N 1000000
int node(int);
struct node{
  int prant;
  int left;
  int right;
};
struct node tree[N];
int child[N],depth[N];
int n;
int getd(int);
void print(int);
int main()
{
  int m,a,i,j;

  scanf("%d",&n);

  for(i=0; i<n; i++){
    tree[i].prant=-1;
    tree[i].left=-1;
    tree[i].right=-1;
  }

  for(i=0; i<n; i++){
    scanf("%d %d",&a,&m);
    for(j=0; j<m; j++){
      scanf("%d",&child[j]);
      
      tree[child[j]].prant=a;

      if(j==0) tree[a].left=child[0];
      else tree[child[j-1]].right=child[j];
    }
  }

  for(i=0; i<n; i++){
    depth[i]=getd(i);
  }

  for(i=0; i<n;i++) print(i);

  return 0;
}

int getd(int x)
{
  int d=0;
  while(tree[x].prant>=0){
    x=tree[x].prant;
    d++;
  }
  return d;
}

void print(int x)
{
  int i,cnt=0;

  printf("node %d: parent = %d, depth = %d, ",x,tree[x].prant,depth[x]);

  if(tree[x].prant==-1) printf("root, [");
  else if(tree[x].left==-1) printf("leaf, [");
  else printf("internal node, [");

  x=tree[x].left;
  while(x!=-1){
    if(cnt==0) printf("%d",x);
    else printf(", %d",x);

    x=tree[x].right;
    cnt++;
  }
  printf("]\n");
}
