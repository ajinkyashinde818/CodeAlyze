#include<stdio.h>
#include<stdlib.h>
#define N 100000
#define NIL -1
struct Node{
  int parent;
  int depth;
  int root;
};
struct Node A[N];
int B[N];

void res(int r, int w)
{
  
  B[r] = w;
  if(A[r].root !=NIL) res(A[r].root,w);
  if(A[r].depth != NIL) res(A[r].depth,w+1);
}

void output(int n)
{
  int i,p;
  printf("node %d: parent = %d, depth = %d, ",n,A[n].parent,B[n]);
    if(A[n].parent ==NIL) printf("root, [");
    else if(A[n].depth ==NIL) printf("leaf, [");
    else printf("internal node, [");

    for(i=0, p=A[n].depth; p!=NIL; i++,p=A[p].root){
      if(i)printf(", ");
      printf("%d",p);
    }
    printf("]\n");
}
int main()
{
  int i,j,n,m,l,s,q,r;

  scanf("%d",&n);

  for(i=0; i<n; i++){
    A[i].parent =A[i].depth =A[i].root =NIL;
  }
  for(i=0; i<n; i++){
    scanf("%d",&m);
    scanf("%d",&l);
    
    for(j=0; j<l; j++){
      scanf("%d",&s);
      
      if(j==0)A[m].depth = s;
      else A[q].root =s;
      q = s;
      A[s].parent = m;
    }
  }
    for(i=0; i<n; i++) if(A[i].parent==NIL) r = i;
 
  res(r, 0);
  for(i=0; i<n; i++) output(i);
    
    return 0;
}
