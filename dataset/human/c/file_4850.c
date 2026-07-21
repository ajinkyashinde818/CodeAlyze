#include <stdio.h>
#define N 100001
#define NIL -1
int n;
struct Node{
  int p,l,r;
};
struct Node T[N];

int CalcDepth(int id){
  if(T[id].p==NIL) return 0;
  return CalcDepth(T[id].p)+1;
}

int CalcHeight(int id){
  int i,c,q=0;
  for(i=0;i<n;i++){
    if(T[i].p==id){
      c=1+CalcHeight(i);
      if(q<c) q=c;
    }
  }
    return q;
}

int main(){
  int i,j,id,k,c,pr;
  int sib[N], deg[N], left, right;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    deg[i]=0;
    T[i].p=NIL;
    T[i].l=NIL;
    T[i].r=NIL;
    sib[i]=NIL;
  }

  for(i=0;i<n;i++){
    scanf("%d %d %d",&id,&left,&right);
    if(left!=NIL && right!=NIL){/*There are right and left*/
      deg[id]=2;
      T[id].l=left;
      T[id].r=right;
      T[left].p=id;
      T[right].p=id;
      sib[left]=right;
      sib[right]=left;
    }else if(left!=NIL && right==NIL){/*There is only left*/
      deg[id]=1; 
      T[id].l=left;
      T[left].p=id;
    }else if(left==NIL && right!=NIL){/*There is only right*/
      deg[id]=1; 
      T[id].r=right;
      T[right].p=id;
    }else{/*There is neither*/
      deg[id]=0;
    }
  }

  for(i=0;i<n;i++){
    printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, ",i,T[i].p,sib[i],deg[i],CalcDepth(i),CalcHeight(i));
    if(T[i].p==NIL) printf("root\n"); 
    else if(T[i].l==NIL&&T[i].r==NIL) printf("leaf\n");
    else printf("internal node\n");
  }
  return 0;
}
