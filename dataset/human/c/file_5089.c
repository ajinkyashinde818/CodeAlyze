#include<stdio.h>
#include<stdlib.h>
typedef struct list{
  int parent;
  int sibling;
  int degree;
  int depth;
  int height;
  int left;
  int right;
}node_list;

void renew_depth(node_list *,int);

int main(){
  int i,j,n,L,R,id,degree,*leaf,leaf_count=0;
  node_list *A;

  scanf("%d",&n);

  A = malloc(sizeof(node_list)*n);
  leaf = malloc(sizeof(int)*n);
  for(i=0;i<n;i++){
    A[i].parent = -1;
    A[i].depth = 0;
    A[i].sibling = -1;
    A[i].height = 0;
  }
  for(i=0;i<n;i++){
    scanf("%d %d %d",&id,&L,&R);
    A[id].left = L;
    A[id].right = R;
    if(L != -1){
      degree++;
      A[L].sibling = R;
      A[L].parent = id;
      A[L].depth ++;
    }
    if(R != -1){
       degree++;
      A[R].sibling = L;
      A[R].parent = id;
      A[R].depth ++;
    }
    if(degree == 0)leaf[leaf_count++]=id;
    else{
    A[id].degree = degree;
    degree = 0;
    }
  }
  for(i=0;i<n;i++){
    if(A[i].parent ==  -1){
      renew_depth(A,i);
      break;
    }
  }
  for(i=0;i<leaf_count;i++){
    j = leaf[i];
    while(A[j].parent != -1){
      A[A[j].parent].height = A[j].height+1 >  A[A[j].parent].height ? A[j].height+1 : A[A[j].parent].height ;
      j = A[j].parent;
    }
  }

  for(i=0;i<n;i++){ 
    printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, ",i,A[i].parent,A[i].sibling,A[i].degree,A[i].depth,A[i].height);
    if(A[i].parent == -1)printf("root\n");
    else if(A[i].degree == 0)printf("leaf\n");
    else printf("internal node\n");
  }
  free(leaf);
  free(A);
  return 0;
}

void renew_depth(node_list *A,int i){
  if(A[i].left != -1){
    A[A[i].left].depth += A[i].depth ;
    renew_depth(A,A[i].left);
  }
  if(A[i].right != -1){
    A[A[i].right].depth +=  A[i].depth ;
    renew_depth(A,A[i].right);
  }
}
