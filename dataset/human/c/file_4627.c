#include <stdio.h>
#include <stdlib.h>
 
typedef struct{
  int id;
  int parent;
  int sibling;
  int depth;
  int height;
  int degree;
  int left;
  int right;
} node;
 
node tree[25];
 
 
int main(){
 
  int n,i,j,count,k,m,l,r;
  scanf("%d",&n);
 
 for(i=0;i<n;i++){
   tree[i].parent = -1;
   tree[i].sibling = -1;
   tree[i].degree = 0;
   tree[i].depth = 0;
   tree[i].height = 0;
 
 }
  
 for(i=0;i<n;i++){
   scanf("%d",&m);
   tree[m].id = m;
   scanf("%d%d",&tree[m].left,&tree[m].right);
   tree[tree[m].left].parent = m;
   if( tree[m].left != -1) tree[m].degree++;
   tree[tree[m].left].sibling = tree[m].right ;
 
   tree[tree[m].right].parent = m;
   if( tree[m].right != -1) tree[m].degree++;
   tree[tree[m].right].sibling = tree[m].left;
   }
 
 for(i=0;i<n;i++){
   j = i;
   while(tree[j].parent != -1){
     j = tree[j].parent;
     tree[i].depth++; 
   }
 }
 
for(i=0;i<n;i++){
  tree[i].height= height(i);
 }
 
 
 
  
 for(i=0;i<n;i++){
   printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, ",tree[i].id,tree[i].parent,tree[i].sibling,tree[i].degree,tree[i].depth,tree[i].height);
   if(tree[i].parent == -1) printf("root\n");
   else if(tree[i].left == -1 && tree[i].right == -1) printf("leaf\n");
   else printf("internal node\n");
 }
  
 return 0;
}
     
     
int height(int x){
  int r,l;
  if(tree[x].left == -1 && tree[x].right == -1) return 0;
  if(tree[x].left == -1) l=1+0;
  else  l=1+height(tree[x].left);
  if(tree[x].right == -1) r=1+0;
  else r=1+height(tree[x].right);
  if(l<=r) return r;
  else return l;
}
