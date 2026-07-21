#include<stdio.h>

typedef struct{
  int parent;
  int left;
  int right;
}Tree;

Tree t[100000];
int num,dep[100000],hei[100000];

void print(int);
void setDep(int,int);
int setHei(int);
int getSib(int);

int main(){
  int v,k,l,r,c,i,root = 0;

  scanf("%d",&num);
  for(i = 0; i< num; i++){
    t[i].parent = -1;
    t[i].left = -1;
    t[i].right = -1;
  }

  for(i = 0; i< num; i++){
    scanf("%d %d %d",&v,&l,&r);
  
    t[v].left = l;
    t[v].right = r;

    if(l != -1)t[l].parent = v;
    if(r != -1)t[r].parent = v;
  }

  for(i = 0; i < num; i++){
    if(t[i].parent == -1)root = i;
  }

  setDep(root,0);
  setHei(root);

  for(i = 0; i< num; i++)print(i);
  return 0;
}


void print(int u){
  
  int i,c;
  printf("node %d: parent = %d, sibling = %d, ",u,t[u].parent,getSib(u));
  int degree = 0;
  if(t[u].left != -1)degree++;
  if(t[u].right != -1)degree++;
  printf("degree = %d, depth = %d, height = %d, ",degree,dep[u],hei[u]);
    
  if(t[u].parent == -1)printf("root\n");
  else if(t[u].left == -1 && t[u].right == -1)printf("leaf\n");
  else printf("internal node\n");
}


void setDep(int u,int p){

  if(u == -1)return;
  dep[u] = p;
  setDep(t[u].right,p+1);
  setDep(t[u].left,p+1);


}


int setHei(int u){
  int h1 = 0,h2 = 0,h;

  if(t[u].left != -1){
    h1 = setHei(t[u].left)+1;
  }
  if(t[u].right != -1){
    h2 = setHei(t[u].right)+1;
  }
  if(h1 > h2)hei[u] =h1;
  else hei[u] = h2;

  return hei[u];
}

int getSib(int u){

  if(t[u].parent == -1)return -1;
  if(t[t[u].parent].left != u && t[t[u].parent].left != -1) return t[t[u].parent].left;
  if(t[t[u].parent].right != u && t[t[u].parent].right != -1) return t[t[u].parent].right;
  
  return -1;
}
