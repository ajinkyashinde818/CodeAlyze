#include<stdio.h>
#define NIL -1
#define MAX 10000

 struct Node{
         int parent;
         int left;
         int right;
         };

 struct Node N[MAX];
 int D[MAX],H[MAX],n;

 int depth(int u,int p){
            if(u==NIL)return;
            D[u]=p;
            depth(N[u].right,p+1);
            depth(N[u].left,p+1);
            }

 int height(int u){
        int h1=0;int h2=0;
        if(N[u].right!=NIL){h1=height(N[u].right)+1;}
        if(N[u].left!=NIL){h2=height(N[u].left)+1;}
        return H[u]=h1>h2?h1:h2;
        }

 int sibling(int u){
        if(N[u].parent==NIL)return NIL;
        if(N[N[u].parent].left!=u&&N[N[u].parent].left!=NIL)return N[N[u].parent].left;
        if(N[N[u].parent].right!=u&&N[N[u].parent].right!=NIL)return N[N[u].parent].right;
        return NIL;
        }

 void print(int u){
                   printf("node %d:",u);
                   printf(" parent = %d,",N[u].parent);
                   printf(" sibling = %d,",sibling(u));
                   int deg=0;
                   if(N[u].left!=NIL)deg++;
                   if(N[u].right!=NIL)deg++;
                   printf(" degree = %d,",deg);
                   printf(" depth = %d,",D[u]);
                   printf(" height = %d,",H[u]);

                   if(N[u].parent==NIL)printf(" root\n");
                   else if(N[u].left==NIL&&N[u].right==NIL)printf(" leaf\n");
                   else printf(" internal node\n");
                   }



int main(){
       int i,v,l,r,root=0;
       scanf("%d",&n);
       for(i=0;i<n;i++)N[i].parent=NIL;
       for(i=0;i<n;i++){
               scanf("%d%d%d",&v,&l,&r);
               N[v].left=l;
               N[v].right=r;
               if(l!=NIL)N[l].parent=v;
               if(r!=NIL)N[r].parent=v;
               }

       for(i=0;i<n;i++)if(N[i].parent==NIL)root=i;
       depth(root,0);
       height(root);

       for(i=0;i<n;i++)print(i);

       return 0;
       }
