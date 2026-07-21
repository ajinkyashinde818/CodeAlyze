#include<stdio.h>
#include<string.h>
#define inf 1072114514

int dx4[4]={1,-1,0,0};
int dy4[4]={0,0,1,-1};

#define size 16777216

int deque[size],fpt=size/2,bpt=(size/2)+1;

void push(int v,int isbk){
  if(isbk){deque[bpt]=v;bpt++;}
  else{deque[fpt]=v;fpt--;}
}

int pop(int isbk){
  int r;
  if(isbk){bpt--;r=deque[bpt];deque[bpt]=inf;}
  else{fpt++;r=deque[fpt];deque[fpt]=-inf;}
  return r;
}

int main(){
  int h,w;
  int sh,sw;
  int th,tw;
  char s[1024][1024];
  int dl[1024][1024];
  scanf("%d%d%d%d%d%d",&h,&w,&sh,&sw,&th,&tw);
  for(int i=0;i<=w+1;i++){s[0][i]='.';s[h+1][i]='.';}
  for(int i=1;i<=h;i++){
    s[i][0]='.';
    scanf("%s",&s[i][1]);
    s[i][w+1]='.';
    for(int j=1;j<=w;j++){dl[i][j]=inf;}
  }
  push(1024*sh+sw,0);
  dl[sh][sw]=0;
  while(fpt+1!=bpt){
    int v,ci,cj,ni,nj;
    v=pop(0);
    ci=(v/1024);cj=(v%1024);
    //printf("%d %d : %d\n",ci,cj,dl[ci][cj]);
    if(ci==th&&cj==tw){printf("%d\n",dl[th][tw]);return 0;}
    for(int k=0;k<4;k++){
      ni=ci+dx4[k];nj=cj+dy4[k];
      if(s[ni][nj]=='#'){continue;}
      if(dl[ci][cj]<dl[ni][nj]){
        dl[ni][nj]=dl[ci][cj];
        push(1024*ni+nj,0);
      }
    }
    for(int i=-2;i<=2;i++){
      for(int j=-2;j<=2;j++){
        ni=ci+i;nj=cj+j;
        if(s[ni][nj]=='#'){continue;}
        if(dl[ci][cj]+1<dl[ni][nj]){
          dl[ni][nj]=dl[ci][cj]+1;
          push(1024*ni+nj,1);
        }
      }
    }
  }
  puts("-1");
  return 0;
}
