#include <stdio.h>
#include <stdlib.h>


typedef struct{
  int parent;
  int cnum;
  int child[2];
} Node;

int hieght(int);

Node A[100000];

int main(){
  int n;
  int N;
  int num;
  int i,j;
  int jag;
  int depth;
  int jag1;
  int h;
  
  
  
  scanf("%d",&n);
  for(i=0;i<n;i++) A[i].parent=-1;
  for(i=0;i<n;i++){
    scanf("%d",&num);
    A[num].cnum=0;
    for(j=0;j<2;j++){
      scanf("%d",&A[num].child[j]);
      if(A[num].child[j]!=-1){
        A[A[num].child[j]].parent=num;
        A[num].cnum++;
    }
  }
}
  for(i=0;i<n;i++){
    printf("node %d: parent = %d, ",i,A[i].parent);
    jag=A[i].parent;
    //sibling
    jag1=0;
    printf("sibling = ");
    for(j=0;j<A[jag].cnum;j++){
       if(jag==-1) break;
       if(A[jag].child[j]!=i&&A[jag].child[j]!=-1) {
          printf("%d, ",A[jag].child[j]);
          jag1=1;
       }
    }
    if(jag1==0) printf("-1, ");
    //
    //defree
    printf("degree = %d, ",A[i].cnum);
    //
    depth=0;
    while(1){
      if(jag==-1){
	printf("depth = %d, ",depth);
	break;
      }
      else{
	depth++;
	jag=A[jag].parent;
      }
    }
    //height
    h=height(i);
    printf("height = %d, ",h);   

    if(depth==0) printf("root\n");
    else if(A[i].cnum!=0) printf("internal node\n");
    else printf("leaf\n");
  }

  return 0;
}

int height(int i){
   int hr=0;
   int hl=0;
   
   if(A[i].cnum==0) return 0;

   hl=height(A[i].child[0]);
   hr=height(A[i].child[1]);
   if(hl>hr) {
     hl++;
     return hl;
   }
   else {
     hr++;
     return hr;
   }
}
