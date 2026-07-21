/* B Binary Trees */

#include<stdio.h>

int T[26][3];/*T[n][0]=P, T[n][1]=L(left child), T[n][2]=R(right child)*/

int main(){
  int i,j;
  int n, id, l, r;
  int temp,count, height;

  scanf("%d",&n);

  /* initialize T[n][3]*/
  for(i=0;i<n;i++){
    for(j=0;j<3;j++){
      T[i][j]=-1;
    }
  }

  for(i=0;i<n;i++){
    scanf("%d %d %d",&id,&l,&r);
    T[id][1]=l;
    T[l][0]=id;
    T[id][2]=r;
    T[r][0]=id;
  }

  /*print*/
  for(i=0;i<n;i++){
    printf("node %d: ",i);
    printf("parent = %d, ",T[i][0]);
    if(T[i][0]==-1){
      printf("sibling = -1, ");
    }else if(T[T[i][0]][1]==i){
      printf("sibling = %d, ",T[T[i][0]][2]);
    }else{
      printf("sibling = %d, ",T[T[i][0]][1]);
    }
    printf("degree = ");
    if(T[i][1]!=-1&&T[i][2]!=-1)printf("2, ");
    else if(T[i][1]!=-1||T[i][2]!=-1)printf("1, ");
    else printf("0, ");


    temp=T[i][0];
    printf("depth = ");
    count=0;
    if(temp!=-1){
      while(1){
	count++;
	temp=T[temp][0];
	if(temp==-1)break;
      }
      printf("%d, ",count);
    }else{
      printf("0, ");
    }

    printf("height = ");
    
    
    /* search leaf */
    height=0;
    for(j=0;j<n;j++){
      if(T[j][1]==-1&&T[j][2]==-1&&T[j][0]!=-1){
	/*count height*/
	temp=j;
	count=0;
	while(1){
	  count++;
	  if(T[temp][0]==i){
	    if(height<count){
	      height=count;
	    }
	    break;
	  }else{
	    temp=T[temp][0];
	    if(T[temp][0]==-1){
	      break;
	    }
	  }
	}
      }
    }
    printf("%d, ",height);
    
    /*root, internal node or leaf*/
    if(T[i][0]==-1)printf("root");
    else if(T[i][1]==-1&&T[i][2]==-1)printf("leaf");
    else printf("internal node");
    printf("\n");
  }
  return 0;
}
