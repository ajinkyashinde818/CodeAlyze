#include <stdio.h>

struct Node {int p,l,r;};

struct Node T[100005];
int n,D[100005],H[100005];

void print(int u){
  int i,c;
  printf("node %d: ",u);
  printf("parent = %d, ",T[u].p);
  if(T[u].p==-1)printf("sibling = -1, ");
  else if(T[T[u].p].r!=u&&T[T[u].p].r!=-1) printf("sibling = %d, ",T[T[u].p].r);
  else if(T[T[u].p].l!=u&&T[T[u].p].l!=-1) printf("sibling = %d, ",T[T[u].p].l);
  else printf("sibling = -1, ");
					     
  c=0;
  if(T[u].l!=-1) c++;
  if(T[u].r!=-1) c++;
  printf("degree = %d, ",c);
  printf("depth = %d, ",D[u]);
  printf("height = %d, ",H[u]);

  if(T[u].p==-1) printf("root\n");
  else if(T[u].l==-1&&T[u].r==-1) printf("leaf\n");
  else printf("internal node\n");
}

void De(int u,int d){
  if(u==-1) return;
  D[u]=d;
  De(T[u].r, d+1);
  De(T[u].l, d+1);
}

int He(int u){
  int a=0,b=0;
  if(T[u].l!=-1) a=He(T[u].l)+1;
  if(T[u].r!=-1) b=He(T[u].r)+1;
  if(a>b) return H[u]=a;
  else return H[u]=b;
}


int main(){
  int i,j,a,l,r,root;
  scanf("%d",&n);
  for(i=0;i<n;i++) T[i].p=-1;

  for(i=0;i<n;i++){
    scanf("%d%d%d",&a,&l,&r);
    T[a].l=l;
    T[a].r=r;
    if(l!=-1)T[l].p=a;
    if(r!=-1)T[r].p=a;
    
  }
  for(i=0;i<n;i++){
    if(T[i].p==-1) root=i;
  }

  De(root,0);
  He(root);

  for(i=0;i<n;i++)print(i);

  return 0;
}
