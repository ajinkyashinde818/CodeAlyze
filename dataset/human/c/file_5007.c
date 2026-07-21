#include <stdio.h>
#define MAX 100000

typedef struct{
  int key;
  int parent;
  int degree;
  int depth;
  int height;
  int left;
  int right;
}Data;

int Height(Data T[],int id){
  int l_node, r_node;
  l_node = T[id].left;
  r_node = T[id].right;
  if(T[id].left == -1&&T[id].right == -1){
    return 0;
  }
  else{
    if( r_node == -1){
      T[l_node].height = Height(T,l_node);
      return T[l_node].height + 1;
    }
    if(l_node == -1){
      T[r_node].height = Height(T,r_node);
      return  T[r_node].height + 1;
    }
    
    T[l_node].height = Height(T,l_node);
    T[r_node].height = Height(T,r_node);
    
    if(T[l_node].height<=T[r_node].height){
      return T[r_node].height + 1;
    }
    else return T[l_node].height + 1;
  }
}

int main(){
  int i,j,id,n,child,x,count=0,key,l;  Data T[MAX];
  
  scanf("%d",&n);

  for(i=0;i<n;i++){ //?????????
    T[i].parent = T[i].left = T[i].right = T[i].height = -1;
    T[i].depth = 0;
  }
  
  for(i=0;i<n;i++){ //parent,degree
    scanf("%d",&id);
    for(j=0; j<2; j++){
      scanf("%d",&child);
      if(j==0){
	T[id].left = child;
      }
      else {
	T[id].right = child;
      }
      T[child].parent = id;
    }
    if(T[id].left == -1&&T[id].right == -1){
      T[id].degree = 0;
    }
    else if(T[id].left == -1||T[id].right == -1)T[id].degree = 1;
    else T[id].degree = 2;
  }

  //fprintf(stderr,"wa-i\n");
  
  for(id=0;id<n;id++){ //height
    T[id].height = Height(T,id);
  }

  //fprintf(stderr,"wa-i2\n");
  
  for(id=0;id<n;id++){ //depth
    x = id;
    count = 0;
    while(T[x].parent != -1){
      x = T[x].parent;
      count++;
    }
    T[id].depth = count;
  }

  //fprintf(stderr,"wa-i3\n");
  
  for(id=0;id<n;id++){
    printf("node %d: parent = %d, ",id,T[id].parent);

    if(T[id].parent == -1){
      printf("sibling = -1, ");
    }
    else if(id==T[T[id].parent].left){
      printf("sibling = %d, ",T[T[id].parent].right);
    }
    else {
      printf("sibling = %d, ",T[T[id].parent].left);
    }
    printf("degree = %d, depth = %d, height = %d, ",T[id].degree, T[id].depth,T[id].height);
    
    if(T[id].depth == 0)  printf("root\n");
    else if(T[id].left == -1&&T[id].right == -1)printf("leaf\n");
    else printf("internal node\n");
  }
  
  return 0;
}
