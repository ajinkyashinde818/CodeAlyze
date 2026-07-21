#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void){
  char a[51][51],b[50][51];
  char *p;
  int N,M;
  int i,j,offset;
  int flg=0;

  scanf("%d%d%*c",&N,&M);
  for(i=0;i<N;i++) scanf("%s%*c",a[i]);
  for(i=0;i<M;i++) scanf("%s%*c",b[i]);

  offset=0;
  for(i=0;i+M-1<N;i++){
    if((p=strstr(a[i]+offset,b[0]))==NULL){
      offset=0;
      continue;
    }
    offset=p-a[i];
    flg=1;
    for(j=1;j<M;j++){
      if(strncmp(a[i+j]+offset,b[j],M)!=0){
	flg=0;
	break;
      }
    }
    if(flg==1) break;
    i--;
    offset++;
  }
  puts(flg==1?"Yes":"No");
  return 0;
}
