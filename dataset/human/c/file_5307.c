#include <stdio.h>

int main(){
  int n,m,x;
  int a[12][13]={0};
  int b[12];
  int i,j,k,tmp,pat=1;
  int cost,flag;
  int min_cost=1000000000;
  
  scanf("%d %d %d",&n,&m,&x);
  pat=pat<<n;
  
  for(i=0;i<n;i++){
    scanf("%d",&a[i][0]);
    for(j=1;j<=m;j++){
      scanf("%d",&a[i][j]);
    }
  }
  
  //sort by cost
  for(i=n;0<i;i--){
    for(j=0;j<i-1;j++){
      if(a[j][0]>a[j+1][0]){
        for(k=0;k<=m;k++){
          tmp=a[j][k];
          a[j][k]=a[j+1][k];
          a[j+1][k]=tmp;
        }
      }
    }
  }
  
  /*
  for(i=0;i<n;i++){
	for(j=0;j<=m;j++){
      printf("%d ",a[i][j]);
    }
    printf("\n");
  }
  printf("\n");*/
  
  //calc cost
  for(i=1;i<=pat;i++){
    //initialize step
    cost=0;
    flag=0;
    for(j=0;j<m;j++){
      b[j]=0;
    }
    
    //calc skillX
    for(j=0;j<n;j++){
      if(((1<<j)&i) !=0){
        cost+=a[j][0];
        for(k=1;k<=m;k++){
          b[k-1]+=a[j][k];
        }
      }
    }
    
    //check skillX
    /*
    printf("%d ",cost);
    for(k=0;k<m;k++){
      printf("%d ",b[k]);
    }
    printf("\n");
    */
    
    for(k=1;k<=m;k++){
      if(b[k-1]<x){
        flag=1;
        break;
      }
    }
    
    if(flag==0 && cost<min_cost){
      min_cost=cost;
    }
  }
  
  if(min_cost<1000000000){
    printf("%d",min_cost);
  } else {
    printf("-1");
  }
}
