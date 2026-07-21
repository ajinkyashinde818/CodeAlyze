#include<stdio.h>
#define MAX 10000
#define NIL -1

struct Node{
  int p,left,right;
};

Node T[MAX];
int n,dep[MAX],h[MAX];

void Depth(int a,int da){
  if(a == NIL){
    return ;
  }
  dep[a] =da;
  Depth(T[a].left,da+1);
  Depth(T[a].right,da+1);
}

int Height(int a){
  int ha1 = 0,ha2 =0;
  if(T[a].left!= NIL){
    ha1 = Height(T[a].left)+1;
  }
  if(T[a].right !=NIL){
    ha2 = Height(T[a].right)+1;
  }
  return h[a]=(ha1 > ha2 ? ha1 : ha2);
}

int getSibling(int sa){
  if(T[sa].p ==NIL){
    return NIL;
  }
  if(T[T[sa].p].left != sa && T[T[sa].p].left != NIL){
    return T[T[sa].p].left;
  }
  if(T[T[sa].p].right != sa && T[T[sa].p].right != NIL){
    return T[T[sa].p].right;
  }
  return NIL;
}

void print(int u){
  printf("node %d: ", u);
  printf("parent = %d, ",T[u].p);
  printf("sibling = %d, ",getSibling(u));
  int deg=0;
  if(T[u].left != NIL){
    deg++;
  }
  if(T[u].right != NIL){
    deg++;
  }
  printf("degree = %d, ",deg);
  printf("depth = %d, ",dep[u]);
  printf("height = %d, ",h[u]);

  if(T[u].p == NIL){
    printf("root\n");
  }
  else if(T[u].left == NIL && T[u].right ==NIL){
    printf("leaf\n");
  }
  else{
    printf("internal node\n");
  }
}

int main(){
  int d,l,r,root,i = 0;
  scanf("%d",&n);

  for(i=0;i<n;i++){
    T[i].p = NIL;
  }

  for(i=0;i<n;i++){
    scanf("%d %d %d",&d,&l,&r);
    T[d].left = l;
    T[d].right = r;
    if(l != NIL){
      T[l].p =d;
    }
    if(r != NIL){
      T[r].p = d;
    }
  }
    for(i=0;i<n;i++){
      if(T[i].p ==NIL){
	root = i;
      }
    }
    Depth(root,0);
    Height(root);

    for(int i=0;i<n;i++){
      print(i);
    }

    return 0;
  }
