#include<stdio.h>
#define NIL -1
typedef struct{
  int p,l,r;
}node;

void print(node *u,int i){
  int p=u[i].p;
  
  printf("node %d: ",i);
  printf("parent = %d, ",u[i].p);
  printf("sibling = %d, ",sibling(u,i));
  printf("degree = %d, ",degree(u,i));
  printf("depth = %d, ",depth(u,i));
  printf("height = %d, ",height(u,i));
  if(u[i].p == NIL) printf("root\n");
  else{
    if(u[i].l == NIL && u[i].r == NIL) printf("leaf\n");
    else printf("internal node\n");
  }
}

int sibling(node *u, int i){
  int p = u[i].p;

  if(p == NIL) return NIL;
  if(u[p].l == i) return u[p].r;
  else return u[p].l;
}

int degree(node *u,int i){
  int count=0;

  if(u[i].l != NIL) count++;
  if(u[i].r != NIL) count++;
  
  return count;
}

int depth(node *u,int x){
  int count=0,temp;

  while(u[x].p != NIL){
    count++;
    temp = u[x].p;
    x = temp;
  }
  return count;
}

//
int height(node *u, int x){
  int count1=0,count2=0;
  int res;
  
  if(u[x].l != NIL) count1 = height(u,u[x].l)+1;
  if(u[x].r != NIL) count2 = height(u,u[x].r)+1;
  res = (count1>=count2) ? count1 : count2;
  count1 = count2 = 0;
  
  return res;
}

int main(){
  node u[30];
  int n,id,l,r;
  int i;
  
  scanf("%d",&n);
  for(i=0;i<n;i++) u[i].p = u[i].l = u[i].r = NIL;
  for(i=0;i<n;i++){
    scanf("%d%d%d",&id,&l,&r);
    u[id].l = l;
    u[id].r = r;
    u[l].p = u[r].p = id;
  }
  for(i=0;i<n;i++) print(u,i);
  
 
return 0;
}
