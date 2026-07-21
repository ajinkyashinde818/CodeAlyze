#include<stdio.h>
#define N 5
int find(int board[10][N],int h);
void seiti(int board[10][N],int h);
int main(void){
  int board[10][N],h,j,i,point,point_sum=0;
  //  int z,a;
  while(1){
    scanf("%d",&h);
    if(h==0)
      break;
    point=0;
    point_sum=0;
    for(i=0;i<h;i++){
      
      for(j=0;j<N;j++){
	scanf("%d",&board[i][j]);
      }
    }
    while(1){
      point=find(board,h);
      if(point==0)
	break;
      point_sum=point+point_sum;
      /*
	printf("mae\n");
      for(a=0;a<h;a++){
	for(z=0;z<N;z++){
	  printf("%d ",board[a][z]);
	}
	printf("\n");
      }
      printf("s%d\nseiti\n",point_sum);
      */
      seiti(board,h);
      /*
	for(a=0;a<h;a++){
	for(z=0;z<N;z++){
	  printf("%d ",board[a][z]);
	}
	printf("\n");
      }
      */
    }
    printf("%d\n",point_sum);
  }
    return 0;
}
int find(int board[10][N],int h){
  int i,j,count,x,len,point,point_sum=0;
  
  for(i=0;i<h;i++){
    count=0;
    point=0;
    for(j=1;j<N;j++){
      if(board[i][j]==board[i][j-1] && board[i][j]!=0){
	count++;
      }
      else{
	count=0;
      }
      if(count>=2){
	point=board[i][j-count]*(count+1);
	len=count;
	x=j-count;
      }
    }
    if(point!=0){
      for(j=x;j<x+len+1;j++){
	board[i][j]=0;
      }
      point_sum=point+point_sum;
    }
  }
    return point_sum;
}
void seiti(int board[10][N],int h){
  int i,j,flag,count=0;
  while(1){
    flag=0;
    for(i=h-1;i>0;i--){
      for(j=0;j<N;j++){
	if(board[i][j]==0){
      	  if(board[i-1][j]==0){
	    flag=1;
	  }
	  //	  printf("%d %d,",i,j);
	  board[i][j]=board[i-1][j];	  
	  board[i-1][j]=0;
	}
      }
    }
    if(flag==1)
      count++;
    if(flag==0 || count==h)
      break;
  }
}
