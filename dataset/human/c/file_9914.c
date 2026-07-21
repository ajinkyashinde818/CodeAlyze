#include <stdio.h>
#include <stdlib.h>

typedef struct{
  int id;
  int parent;
  int depth;
  int k;
  int *child;
} node;

node tree[100000];


int main(){

  int n,i,j,count,k,m;
  scanf("%d",&n);

 for(i=0;i<n;i++){
   tree[i].parent = -1;
   tree[i].depth = 0;
 }
 
 for(i=0;i<n;i++){
   scanf("%d",&m);
   tree[m].id = m;
   scanf("%d",&tree[m].k);
   tree[m].child = malloc(tree[m].k * sizeof(int));
   for(j=0;j<tree[m].k;j++){
     scanf("%d",&tree[m].child[j]);
     tree[tree[m].child[j]].parent = m;
   }
 }

 for(i=0;i<n;i++){
   j = i;
   while(tree[j].parent != -1){
     j = tree[j].parent;
     tree[i].depth++; 
   }
 }

 
 for(i=0;i<n;i++){
   printf("node %d: parent = %d, depth = %d, ",tree[i].id,tree[i].parent,tree[i].depth);
   if(tree[i].parent == -1) printf("root, [");
   else if(tree[i].k == 0) printf("leaf, [");
   else printf("internal node, [");
   for(k=0;k<tree[i].k;k++){
     printf("%d",tree[i].child[k]);
     if(k != tree[i].k - 1) printf(", ");
   }
   printf("]\n");
   free(tree[i].child);
 }
 
 return 0;
}
