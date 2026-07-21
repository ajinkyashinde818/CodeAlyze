#include<stdio.h>
#define null -1

 struct Node{
         int parent;
         int left;
         int right;
         };

 struct Node node[100001];



 int deep(int u){
         int d=0;
         while(node[u].parent!=null){
                     u=node[u].parent;
                     d++;
                     }
         return d;
         }

 void print(int i){
         int j,c;
         printf("node %d: ",i);
         printf("parent = %d, ",node[i].parent);
         printf("depth = %d, ",deep(i));

         if(node[i].parent==null)printf("root, "); 
         else if(node[i].left==null)printf("leaf, ");
         else printf("internal node, ");

         c=node[i].left;
         printf("[");
         for(j=0;c!=null;j++){
                  if(j)printf(", ");
                  printf("%d",c);
                  c=node[c].right;
                 }
         printf("]\n");
         }
         
         


 int main(){
         int i,n,c,j,root,v,C,left;
         scanf("%d",&n);
         for(i=0;i<n;i++){node[i].right=node[i].left=node[i].parent=null;}
         for(i=0;i<n;i++){
                   scanf("%d%d",&v,&c);
                   for(j=0;j<c;j++){
                             scanf("%d",&C);
                             if(j==0)node[v].left=C;
                             else node[left].right=C;
                             left=C;
                             node[C].parent=v;
                             }
                   }


         for(i=0;i<n;i++){print(i);}
         return 0;
         }
