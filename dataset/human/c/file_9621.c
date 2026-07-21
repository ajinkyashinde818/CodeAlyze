#include<stdio.h>

int is_same(char hit[],char ticket[]){
  int i;
  int digit;

  for(i=7;i>=0;i--)
    if(hit[i]=='*')
      break;
  digit=i;

  for(i=7;i>digit;i--)
    if(hit[i]!=ticket[i])
      return 0;

  return 1;
}

int main(void){
  int i,j;
  int n,m;
  char hit[100][9];
  int prize[100];
  char ticket[1000][9];
  int cur;

  for(;;){
    scanf("%d%d",&n,&m);
    if(!n)
      break;

    for(i=0;i<n;i++)
      scanf("%s%d",hit[i],&prize[i]);
    for(i=0;i<m;i++)
      scanf("%s",ticket[i]);

    cur=0;
    for(i=0;i<m;i++){
      for(j=0;j<n;j++)
        if(is_same(hit[j],ticket[i])){
          cur+=prize[j];
          break;
        }
    }

    printf("%d\n",cur);
  }

  return 0;
}
