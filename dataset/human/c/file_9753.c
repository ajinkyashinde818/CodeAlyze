#include<stdio.h>


typedef struct node{  
  int parent;
  int right;
  int left;


} tree1;

tree1 A[1000000];
int number;

int D[1000000];


void depth(int i,int p){
  int d=0;
  D[i]=p;


  if(A[i].right!=-10)
    {depth(A[i].right,p);}
  if(A[i].left!=-10)
    {depth(A[i].left,p+1);}
}






int main(){



  
  scanf("%d",&number);
  

  int i,j;

  

  for(i=0;i<number;i++){
    

    A[i].parent=A[i].right=A[i].left=-10;
  }


  
  int n;


  int node,c_degree;
  int c_node;

  int l;
 

  //節点番号と子の次数を入れていく
  for(i=0;i<number;i++){
    scanf("%d%d",&node,&c_degree);



    //子の節点番号を入れていく
    for(j=0;j<c_degree;j++){
      scanf("%d",&c_node);

    
      
      if(j==0){A[node].left=c_node;}

      else{A[ l ].right=c_node;}
	
       	l=c_node;
	A[c_node].parent=node;
      }


    
    }
   
  

  int r;

  
  for(i=0 ; i<number ; i++){
    if(A[i].parent==-10){r=i;}
  }

  
  depth(r,0);


  for(i=0;i<number;i++){
    printf("node %d: parent = ",i);
    if(A[i].parent==-10){A[i].parent=-1;
      printf("%d, depth = %d,",A[i].parent,D[i]);
      A[i].parent=-10;}
    else {printf("%d, depth = %d,",A[i].parent,D[i]);}

    
    if(A[i].parent==-10){printf(" root, [");}
    else if(A[i].left==-10){printf(" leaf, [");}
    else {printf(" internal node, [");}

    int h;

    for(j=0,h=A[i].left;h!=-10;j++,h=A[h].right){
      if(j>0){printf(",");}
      if(j==0)printf("%d",h);
      else {printf(" %d",h);}
      

    }
    printf("]\n");

  }

  
  return 0;
}
