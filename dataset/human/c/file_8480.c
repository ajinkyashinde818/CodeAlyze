#include <stdio.h>
#define NUM 10
  
void drop(int puz[][5], int i, int j){
  
int k;
  
for(k=i; k>0; k--)
puz[k][j]=puz[k-1][j];
  
puz[0][j]=0;
  
}
  
  
  
int main(void){
  
  
  
  
int score=0;
int tscore=0;
int count=0;
int h, i, j;
int puz[NUM][5]={0};

replay:
  
while(1){
  
  
  
scanf("%d", &h);
  
if(h==0)
break;
  
  
  
  
  
for(i=0; i<h; i++){
 for(j=0; j<5; j++){
scanf("%d", &puz[i][j]);
  }
}
  
  
 while(1){
  
  
for(i=0; i<h; i++){
  
 for(j=0; j<4; j++){
  
 if(puz[i][j]==puz[i][j+1])
  count++;
 else if(count==2){
  score=score+(3*puz[i][j]);
  puz[i][j]=0;
  puz[i][j-1]=0;
  puz[i][j-2]=0;
  count=0;}
 else if(count==3){
  score=score+(4*puz[i][j]);
  puz[i][j]=0;
  puz[i][j-1]=0;
  puz[i][j-2]=0;
  puz[i][j-3]=0;
  count=0;}
 else
  count=0;
 
  
   }
  
 if(count==2){
  score=score+(3*puz[i][j]);
  puz[i][j]=0;
  puz[i][j-1]=0;
  puz[i][j-2]=0;
  count=0;}
 else if(count==3){
  score=score+(4*puz[i][j]);
  puz[i][j]=0;
  puz[i][j-1]=0;
  puz[i][j-2]=0;
  puz[i][j-3]=0;
  count=0;}
 else if(count==4){
  score=score+(5*puz[i][j]);
  puz[i][j]=0;
  puz[i][j-1]=0;
  puz[i][j-2]=0;
  puz[i][j-3]=0;
  puz[i][j-4]=0;
  count=0;}
  else
  count=0;
  
  
 }

 
   
  
for(i=0; i<h; i++){
 for(j=0; j<5; j++){
  
 if(puz[i][j]==0)
 drop(puz, i, j);
   
 }
}
 
  
if(score==0){
 printf("%d\n", tscore);
 tscore=0;
 goto replay;
}
  
  
tscore=tscore+score;
score=0;

 }
  
 
 }

 return 0;

}
