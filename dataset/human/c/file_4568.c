#include<stdio.h>

int x;
int parent[100001],sibling[100001],degree[100001];


int Height(int);
int Depth(int);

int main(){
  int i,j,id,left,right;

  scanf("%d",&x);

  for(i = 0; i < x; i++){
    parent[i] = -1;
    sibling[i] = -1;
    degree[i] = 0;
  }

  for(i = 0;i < x; i++){

    

    scanf("%d%d%d",&id,&left,&right);

    if(left != -1){
      parent[left] = id;
      sibling[left] = right;
      degree[id]++;

    }

    if(right != -1){
      parent[right] = id;
      sibling[right] = left;
      degree[id]++;
    }
  }

  for(i = 0; i < x; i++){

    int depth = Depth(i);

    printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, ",i,parent[i],sibling[i],degree[i],depth,Height(i));

    if(depth == 0) printf("root\n");

    else if(degree[i] == 0) printf("leaf\n");

    else printf("internal node\n");

  }

  return 0;
}


int Height(int i){

  int j,h = 0,a;

  for(j = 0; j < x ; j++){

    if(parent[j] == i){
       a = Height(j)+1;

      if(a > h) h = a;
    }
  }

  return h;
}


int Depth(int i){

  if(parent[i] == -1) return 0;

  return Depth(parent[i])+1;
}
