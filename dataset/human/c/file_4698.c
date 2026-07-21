#include<stdio.h>
#define Max 10000
#define None -1

typedef struct{
  int parent, left ,right;
}Node;
Node Tree[Max];
int n,Depth[Max],Height[Max];
int Dep(int,int);
int  Hei(int);
void print_out(int );
int Sibling(int);
int main()
{
  int v,l,r,i;
  int root =0;
  scanf("%d",&n);
  for(i=0;i<n;i++)
    Tree[i].parent=None;
    for(i=0;i<n;i++){
      scanf("%d%d%d",&v,&l,&r);
      Tree[v].left=l;
      Tree[v].right=r;
      if(l!=None)Tree[l].parent=v;
      if(r!=None)Tree[r].parent=v;
    }
    for(i=0;i<n;i++)if(Tree[i].parent==None)root=i;

    Dep(root,0);
    Hei(root);
    for(i=0;i<n;i++)print_out(i);
    return 0;
}
  
  Dep(int u,int d){
  if(u==None) return;
  Depth[u] = d;
  Dep(Tree[u].left,d+1);
  Dep(Tree[u].right,d+1);
}
int Hei(int u){
  int h1=0;
  int h2=0;
  if(Tree[u].left!=None)
    h1=Hei(Tree[u].left)+1;
  if(Tree[u].right!=None)
    h2= Hei(Tree[u].right)+1;
      if(h1>h2)return Height[u]=h1;
      else return Height[u]=h2;
}

int Sibling(int u){
  if(Tree[u].parent==None)return None;
  if(Tree[Tree[u].parent].left!=u&&Tree[Tree[u].parent].left!=None)
    return Tree[Tree[u].parent].left;
  if(Tree[Tree[u].parent].right!=u&&Tree[Tree[u].parent].right!=None)
    return Tree[Tree[u].parent].right;
     return None;
     }
  void print_out(int u){
    printf("node %d: ",u);
    printf("parent = %d, ",Tree[u].parent);
    printf("sibling = %d, ",Sibling(u));
    int deg =0;
    if(Tree[u].left!=None)deg++;
    if(Tree[u].right!=None)deg++;
    printf("degree = %d, ",deg);
    printf("depth = %d, ", Depth[u]);
    printf("height = %d, ",Height[u]);

    if(Tree[u].parent ==None){
      printf("root\n");
    }  else if(Tree[u].left == None && Tree[u].right == None){
	printf("leaf\n");
      }else{
	printf("internal node\n");
      }
    }
