#include <stdio.h>
#define MAX 100000

typedef struct{
  int key;
  int parent;
  int depth;
  int left;
  int right;
}Data;

int main(){
  int i,j,id,n,child,x,count=0,key,l;
  Data T[MAX];
  
  scanf("%d",&n);

  for(i=0;i<n;i++){
    T[i].parent = T[i].left = T[i].right = -1;
    T[i].depth = 0;
  }
  
  for(i=0;i<n;i++){
    scanf("%d",&id);
    scanf("%d",&T[id].key);
    key = T[id].key;
    for(j=0; j<key; j++){
      scanf("%d",&child);
      if(j==0)T[id].left = child;
      else T[l].right = child;
      l = child;
      T[child].parent = id;
    }
  }

  for(id=0;id<n;id++){
    x = id;
    count = 0;
    while(T[x].parent != -1){
      x = T[x].parent;
      count++;
    }
    T[id].depth = count;
  }

  for(id=0;id<n;id++){
    printf("node %d: parent = %d, depth = %d, ",id,T[id].parent,T[id].depth);
    if(T[id].depth == 0){
      printf("root, [");
      if(T[id].key == 0)printf("]\n");
      else{
	for( i=0,child = T[id].left ; i<T[id].key-1 ; i++,child = T[child].right){
	  printf("%d, ",child);
	}
	printf("%d]\n",child);
      }
    }
    else if(T[id].key == 0)printf("leaf, []\n");
    else {
      printf("internal node, [");
      for( i=0,child = T[id].left ; i<T[id].key-1 ; i++,child = T[child].right){
	printf("%d, ",child);
      }
      printf("%d]\n",child);
    }
  }
  
  return 0;
}
