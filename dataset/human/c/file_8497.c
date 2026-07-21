#include<stdio.h>
int Block[30][6];
int score=0,n;
void Jo();
int main()
{
  int i,j,score1[1000],m=0;
  while(1){
    scanf("%d",&n);
    if(n==0)break;
    for(i=0;i<20;i++){
      for(j=0;j<6;j++){
	Block[i][j]=0;
      }
    }
    for(i=10;i<n+10;i++){
      for(j=0;j<5;j++){
        scanf("%d",&Block[i][j]);
      }
    }
    Jo();
    score1[m]=score;
    score=0;
    m++;
  }
  for(i=0;i<m;i++){
    printf("%d\n",score1[i]);
  }
  return 0;
}

void Jo()
{
  int i,j,m,s,score1=0,k,l;
  while(1){
    for(i=10;i<n+10;i++){
      for(j=0;j<3;j++){
	if(Block[i][j]!=0 &&Block[i][j]==Block[i][j+1]&&Block[i][j]==Block[i][j+2]){
	  score1+=3*Block[i][j];
	  if(j==0&&Block[i][j]==Block[i][j+3]){
            score1+=Block[i][j];
            if(Block[i][j]==Block[i][j+4])score1+=Block[i][j];
	  }
	  if(j==1 && Block[i][j]==Block[i][j+3])score1+=Block[i][j];
	  j+=2;
}
      }
    }
    if(score1==0)return;
    score+=score1;
    score1=0;
    for(i=10;i<n+10;i++){
      if(Block[i][0]!=0){
        s=Block[i][0];
        m=1;
      }
      for(j=1;j<6;j++){
	if(Block[i][j-1]==0 &&Block[i][j]!=0){
	  s=Block[i][j];
	  m=0;
	}
	if(s==Block[i][j])m++;
	if(m>=3 && s!=Block[i][j]){
	  for(k=j-1;m>0;k--){
            for(l=i;l>0;l--){
	      Block[l][k]=Block[l-1][k];
	    }
            m--;
	  } 
	}
	if(s!=Block[i][j]){
	  s=Block[i][j];
	  m=1;
	}
      }
    }
  }
}
