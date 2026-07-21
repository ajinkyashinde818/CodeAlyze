#include <stdio.h>

int depth(int);




struct Node{
  int parent,leftchild,rightbro;//左子右兄弟表現
};

struct Node node[100001];


int main(){

  int i,j,mom,k,n,child,x,bro;

  scanf("%d",&n);//number of node

  for(i = 0 ; i < n ; i++){
    node[i].parent = -1;
    node[i].leftchild = -1;
    node[i].rightbro = -1;
  }


  for(i = 0 ; i < n ; i++){//各nodeの入力
    scanf("%d %d",&mom,&k);
   
    for(j = 0 ; j < k ; j++){
      scanf("%d",&child);
      
      if(j == 0){
	node[mom].leftchild =child;
	node[child].parent = mom;
	x = child;
 }
      else{
	node[x].rightbro = child;
	node[child].parent = mom;
    	x = child;
      }
    }
  }
  for(i = 0 ; i < n ; i++){
      printf("node %d: parent = %d, depth = %d, ",i , node[i].parent,depth(i));
      if(node[i].leftchild == -1 && node[i].parent!= -1)printf("leaf, ");
      else if(node[i].parent == -1)printf("root, ");
      else if(node[i].leftchild != -1)printf("internal node, ");

      printf("[");

      if(node[i].leftchild != -1){

	printf("%d",node[i].leftchild);

	bro = node[i].leftchild;

	while(1){
	  if(node[bro].rightbro == -1)break;
	  printf(", %d",node[bro].rightbro);
	  bro = node[bro].rightbro;
	}
      }

      printf("]\n");
    }

  return 0;
}
int depth(int k){
  int dep = 0;
  for(dep = 0 ; node[k].parent != -1 ; dep++){
    k = node[k].parent;
  }
  return dep;
}
