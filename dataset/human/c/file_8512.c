#include <stdio.h>

int h,i,j,k,l,m,n,count,score;
int site[5][11],flag;

void yoko(int x,int y) {

  //   printf("count = %d\n",count);  
  //  printf("x = %d\n",x);
  

  if(site[x][y] == site[x+1][y] && site[x][y] != 0 && site[x+1][y] !=0){
    //printf("%d  = %d\n",site[x][y] ,site[x+1][y]);
    count++;
    if(x != 3) yoko(x+1,y);
  }
  else if(count >=3) {
    //  printf("1count = %d\n",count);
    score += site[x-1][y] * count;
    ///printf("x - count +1 = %d\n",x - count + 1);
    for(j=x-count+1;j<=x;j++) site[j][y] = 0;
    count = 1;
    flag  = 1;
    if(x != 3) yoko(x+1,y);

  } if(x != 3) {
    count  = 1;
    yoko(x+1,y);
  } 
  
  if(count >=3 && x == 3) {
    // printf("2count = %d\n",count);
    score += site[x-1][y] * count;
    for(j=x-count+2;j<5;j++) site[j][y] = 0;
    count = 1;
    flag = 1;
  }


  
}

int main() {


  while(1) {

    scanf("%d",&n);
    //    printf("n = %d\n",n);

    if(n == 0) break;

    score = 0;

    for(j=0;j<n;j++){
      for(i=0;i<5;i++) {
	scanf("%d",&site[i][j]);
	//	printf("site[%d][%d] = %d\n",i,j,site[i][j]);

      }
    }
    
    flag = 1;
    while(flag != 0) {
      k=0;
      flag= 0;

      // printf("while flag = %d\n",flag);
      for(i=0;i<n;i++){
	count = 1;
	//	printf("before yoko\n");
	yoko(k,i);
      
      }
      
      /* //check cord
      for(j=0;j<n;j++){
	for(i=0;i<5;i++) {
	  printf("%d ",site[i][j]);
	    
      }
	printf("\n");
	} */  


      for(j=1;j<n;j++) {
	for(i=0;i<5;i++) {
	  if(site[i][j] == 0) {
	    for(k=j;k>0;k--) {
	      site[i][k] = site[i][k-1];
	    }
	    site[i][0] = 0;
	  }
	}
      }
      /* //check cord
      printf("\n");
      for(j=0;j<n;j++){
	for(i=0;i<5;i++) {
	  printf("%d ",site[i][j]);
	    
	}
	printf("\n");
      }  
      printf("\n");
      */

      // printf("flag = %d\n",flag);

    }


    
    printf("%d\n",score);
    
  }

  return 0;
  
}
