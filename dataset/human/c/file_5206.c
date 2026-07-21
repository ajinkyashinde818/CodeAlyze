#include <stdio.h>
#define MAX 10000

struct Node{
  int oya, le ,ri;
};

struct Node Tree[MAX];
int De[MAX],He[MAX];

void depth(int,int);
int height(int);
int sibling(int);
void print(int);

int main(){
int n,i,num,le,ri;
int root=0;
scanf("%d",&n);

for(i=0;i<n;i++)Tree[i].oya=-1;
for(i=0;i<n;i++){
  scanf("%d%d%d",&num,&le,&ri);
  Tree[num].le=le;
  Tree[num].ri=ri;
  if(le != -1) Tree[le].oya = num;
  if(ri != -1) Tree[ri].oya = num;
}
for(i=0;i<n;i++) if(Tree[i].oya == -1) root = i;
depth(root,0);
height(root);
for(i=0;i<n;i++) print(i);

  return 0;
}

void depth(int a,int b){
  if(a==-1)return;
  De[a]=b;
  depth(Tree[a].le, b+1);
  depth(Tree[a].ri, b+1);


}

int height(int a){
  int h1=0;
  int h2 =0;
  if(Tree[a].le != -1) h1= height(Tree[a].le)+1;
  if(Tree[a].ri != -1) h2= height(Tree[a].ri)+1;
  if(h1>h2) return He[a]=h1;
  else return He[a]=h2;
}

int sibling(int a){
  if(Tree[a].oya==-1) return -1;
  if(Tree[Tree[a].oya].le !=a && Tree[Tree[a].oya].le != -1 ){
    return Tree[Tree[a].oya].le;

  }
  if(Tree[Tree[a].oya].ri !=a && Tree[Tree[a].oya].ri != -1 ){
    return Tree[Tree[a].oya].ri;

  }

  return -1;
}

void print(int a){
  int de =0;
  printf("node %d: ",a);
  printf("parent = %d, ",Tree[a].oya);
  printf("sibling = %d, ",sibling(a));
  if(Tree[a].le != -1) de++;
  if(Tree[a].ri != -1) de++;
  printf("degree = %d, ",de);
  printf("depth = %d, ",De[a]);
  printf("height = %d, ",He[a]);

  if(Tree[a].oya == -1){
    printf("root\n");
  }
  else if(Tree[a].le == -1 && Tree[a].ri == -1){
    printf("leaf\n");

  }
  else printf("internal node\n");
}
