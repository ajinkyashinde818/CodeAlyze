#include<stdio.h>
#include<stdlib.h>
#define N 10

typedef struct{
  int parent;
  int left;
  int right;
}Node;

int main(){
  int point,number,i,j,a,b,n,deep=0,place,count=0,k;
  int *Deep;
  int num[N];
  Node *Tree;

  scanf("%d",&n);
  Tree =  ( Node * )malloc( sizeof(Node) * n );
  Deep = ( int * )malloc( sizeof(int) * n );

  for( i = 0 ;i < n;i++ ){

    Tree[i].parent = -1;
    Tree[i].left = -1;
    Tree[i].right = -1;
  }

  for( i = 0; i < n ; i++ ){
    scanf("%d %d",&point,&number);

    for( j = 0 ; j < number ; j++ ){
      scanf("%d",&a);
      if( i == 0 ){
	num[j] = a;
	count++;
      } 
      Tree[a].parent = point;

      if( j == 0 ) Tree[point].left = a;
      else Tree[b].right = a;

      b = a;
    }
  }

  for( i = 0 ; i < n ; i++ ){
    place = i;
    while( Tree[place].parent != -1 ){
      deep++;
      place = Tree[place].parent;
    }
    Deep[i] = deep;
    deep = 0;
  }

  for(i=0;i<n;i++){
    printf("node %d: parent = %d, depth = %d, ",i ,Tree[i].parent ,Deep[i]);
    if(Tree[i].parent==-1)printf("root, ");
    else if(Tree[i].left==-1)printf("leaf, ");
    else printf("internal node, ");

    printf("[");
    for(j=0,a = Tree[i].left; a!=-1;j++,a=Tree[a].right){
      if(j) printf(", ");
      printf("%d",a);
    }
    printf("]\n");
  }
  return 0;
}
