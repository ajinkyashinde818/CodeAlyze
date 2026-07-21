#include<stdio.h>


typedef struct node{  
  int parent;
  int right;
  int left;


} tree1;



tree1 A[1000000];
int number;
int D[1000000];

int H[1000000];


void depth(int i,int p){


  if(i==-1) return;
  D[i]=p;
  depth(A[i].left,p+1);
  depth(A[i].right,p+1);
}


int height(int u){

  int h=0,j=0;


  if(A[u].left!=-1){
    h=height(A[u].left)+1;}

  if(A[u].right!=-1){
    j=height(A[u].right)+1;}

  return H[u]=(h>j?h:j);


}



int sibling(int i){

  if(A[i].parent==-1){return -1;}
  if(A[A[i].parent].left != i && A[A[i].parent].left !=-1){return A[A[i].parent].left;}
  
  if(A[A[i].parent].right != i && A[A[i].parent].right !=-1){return A[A[i].parent].right;}
  

  return -1; 
  }


  








int main(){



  
  scanf("%d",&number);
  

  int i,j;

  

  for(i=0;i<number;i++){
    

    A[i].parent=A[i].right=A[i].left=-1;
  }


  

  int a,r1,r2;
  int root=0;
  //子の値を貰っていく
  for(i=0;i<number;i++){
    scanf("%d%d%d",&a,&r1,&r2);
      
  A[a].left=r1;
  A[a].right=r2;

  if(r1!=-1)A[r1].parent=a;
  if(r2!=-1)A[r2].parent=a;

  }
  
    
    
   
  
  
  for(i=0 ; i<number ; i++){
    if(A[i].parent==-1){root=i;}
  }



  depth(root,0);
  height(root);
  
  
  int deg=0;
  /*出力*/
  for(i=0;i<number;i++){
    deg=0;
    printf("node %d: parent = %d, sibling = %d,",i,A[i].parent,sibling(i));
    
    if(A[i].left !=-1)deg++;
    if(A[i].right !=-1)deg++;



    printf(" degree = %d, depth = %d, height = %d,",deg,D[i],H[i]);




    
    if(A[i].parent==-1){printf(" root\n");}
    else if(A[i].left==-1 && A[i].right == -1){printf(" leaf\n");}
    else {printf(" internal node\n");}

  

  }

  
  return 0;
}
