#include<stdio.h>
#define MAX 100005
#define NIL -1

struct Node{ 
  int p,l,r;
};

struct Node T[MAX]; 

int depth(int u){
  if(T[u].p==NIL)return 0;
  else{
    return 1+depth(T[u].p);
  }
}

int degree(int u){
  if(T[u].l!=NIL && T[u].r!=NIL)return 2;
  else if(T[u].l!=NIL || T[u].r!=NIL)return 1;
  else return 0;
}

int sibling(int p,int u){
  if(p==NIL)return NIL;
  else if(T[p].l==u)return T[p].r;
  else return T[p].l;
}

int height(int u){
  int l_h=0,r_h=0;

  if(u==NIL)return 0;
  
  
    if(T[u].l!=NIL) l_h=height(T[u].l)+1;
    if(T[u].r!=NIL) r_h=height(T[u].r)+1;

    if(l_h>r_h)return l_h;
    else return r_h;
  }


void print(int u){
  printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, ",u,T[u].p,sibling(T[u].p,u),degree(u),depth(u),height(u));

  if(T[u].p==NIL)printf("root\n");
  else if(T[u].l==NIL && T[u].r==NIL)printf("leaf\n");
  else printf("internal node\n");
}

main(){
  int n,i,id,c1,c2;

  scanf("%d",&n);

  for(i=0;i<n;i++){
    T[i].p=T[i].l=T[i].r=NIL;
  }
  
  for(i=0;i<n;i++){
    scanf("%d%d%d",&id,&c1,&c2);

    T[c1].p=id;
    T[c2].p=id;
    T[id].l=c1;
    T[id].r=c2;
  }
  
  for(i=0;i<n;i++){
    print(i);
  }
  return 0;
}
