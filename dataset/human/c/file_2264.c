#include<stdio.h>
#define N 1000

int sq_count(char map[N][N],int y,int x){
  int i,j;

  for(i=1;;i++){
    for(j=0;j<=i;j++){
      if( map[y+i][x+j]!='.' ||
          map[y+j][x+i]!='.')
        return i;
    }
  }
}

int main(void){
  int i,j;
  int n;
  char map[N][N];
  char hoge;
  int SQnum,maxSQnum;

  for(;;){
    scanf("%d",&n);
    if(n==0)
      break;

    for(i=0;i<n;i++){
      scanf("%c",&hoge);
      for(j=0;j<n;j++)
        scanf("%c",&map[i][j]);
    }

    maxSQnum=0;
    for(i=0;i<n;i++){
      for(j=0;j<n;j++){
        if(map[i][j]=='.'){
          SQnum=sq_count(map,i,j);
          if(maxSQnum<SQnum)
            maxSQnum=SQnum;
        }
      }
    }
    printf("%d\n",maxSQnum);
  }

  return 0;
}
