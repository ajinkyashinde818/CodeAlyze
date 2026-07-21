#include<stdio.h>
#define N 100001

int depth(int);
int height(int);
int sibling(int);

int dep;

struct Node{
  int p;
  int l;
  int r;
};
struct Node Tree[N];

 
int main()
{
 
  int i,n,par,left,right,sib,deg=0;
 
  scanf("%d",&n);
  for(i = 0; i < n; i++){
    Tree[i].p = -1;
    Tree[i].l = -1;
    Tree[i].r = -1;
  }
 
  for(i = 0; i < n; i++){
    scanf("%d %d %d",&par,&left,&right);
    Tree[left].p=par;
    Tree[right].p=par;
    Tree[par].l=left;
    Tree[par].r=right;
  }
 
  for(i = 0; i < n; i++){
    printf("node %d: parent = %d, ",i , Tree[i].p);
    
  
    printf("sibling = %d, ",sibling(i));

    if(Tree[i].r != -1)deg++;
    if(Tree[i].l != -1) deg++;
    printf("degree = %d, ",deg);
    deg=0;
    
    printf("depth = %d, ",depth(i));

   printf("height = %d, ",height(i));

   if(Tree[i].p == -1)printf("root");
   else  if(Tree[i].l  == -1 && Tree[i].r == -1)printf("leaf");
   else printf("internal node");
   printf("\n");
  }
  return 0;
}
 
int depth(int k){
  int dep_dep =0;
  for(dep_dep = 0; Tree[k].p != -1; dep_dep++){
    k = Tree[k].p;
  }
  return dep_dep;
}


int height(int u){
  int h1=0,h2=0;
  if(Tree[u].l!=-1){
    h1 = height(Tree[u].l)+1;
  }
  if(Tree[u].r!=-1){
    h2 = height(Tree[u].r)+1;
  }
  if(h1 > h2) return h1;
  else return h2;
}

int sibling(int u){
  int NIL=-1;
  if(Tree[u].p == NIL) return NIL;
  else if(Tree[Tree[u].p].l!=u && Tree[Tree[u].p].l!=NIL){
    return Tree[Tree[u].p].l;
  }
  else if(Tree[Tree[u].p].r!=u && Tree[Tree[u].p].r!=NIL) {
    return Tree[Tree[u].p].r;
  }
  return NIL;
}
