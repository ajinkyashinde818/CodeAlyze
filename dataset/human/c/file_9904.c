#include<stdio.h>

#define MAX 100000

int getdepth(int);

typedef struct{
  int parent;
  int left;
  int right;
}node;

node T[MAX];

int main(){
  int i, j, sib, deg, id, k, n, depth;

  scanf("%d",&n);

  for(i=0;i<n;i++) T[i].parent = T[i].left = T[i].right = -1;

  for(i=0 ; i<n ; i++){
    
    scanf("%d%d",&id,&k);

    for(j=0 ; j<k ; j++){

      scanf("%d",&deg);

      if(j==0) T[id].left = deg;

      else T[sib].right = deg;

      sib = deg;
      T[deg].parent = id;
    }
  }

  for(i=0 ; i<n ; i++){

    depth = getdepth(i);
    //printf("here\n");
    if(depth==0) printf("node %d: parent = %d, depth = %d, root, ", i, T[i].parent, depth);

    else if(T[i].left==-1) printf("node %d: parent = %d, depth = %d, leaf, ", i, T[i].parent, depth);

    else printf("node %d: parent = %d, depth = %d, internal node, ", i, T[i].parent, depth);
    //printf("here\n");
    printf("[");

    if(T[i].left != -1){
      id = T[i].left;
      printf("%d",id);
      
      while(id != -1){
	id = T[id].right;
	
	if(id != -1) printf(", %d",id);
      }
    }

    printf("]\n");

  }
  return 0;
}

int getdepth(int i){//printf("in\n");
  int id = T[i].parent;
  int cnt = 0;

  while(id != -1){
    id = T[id].parent;
    cnt++;
    //printf("while\n");
  }

  return cnt;
}
