#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define df 0
#define MAX 100010
int dc=100000;
int dist(int a,int b){
  return (a<b)?b-a:a-b;
}

int main(){
  if(df)printf("*** debug mode ***\n");
  char s[MAX],d[MAX];
  int idx[MAX],i;
  scanf(" %s",s);
  int len=strlen(s);
  if(df)printf("%s:%d\n",s,len) ;
  int j=0;
  idx[0]=-1;
  for(i=0;i<len;i++){
    if(s[i]!='x'){
      d[j]=s[i];
      idx[j+1]=i;
      j++;
    }
  }
  if(df)printf("\n");
  idx[j+1]=len;
  int d_len=j,flag=1,m=(1+d_len)/2;
  if(df){
    for(i=0;i<d_len;i++){
      printf("%c",d[i]);
    }
    printf("\n");
    for(i=0;i<d_len+2;i++){
      printf("%d",idx[i]);
    }
    printf("\n");
  }
  for(i=0;i<d_len;i++){
    if(d[i]!=d[d_len-i-1])flag=0;
  }
  if(flag==0){
    printf("-1");
    return 0;
  }
  int sum=0;
  for(i=0;i<m;i++){
    sum+=dist(idx[i+1]-idx[i],idx[d_len-i+1]-idx[d_len-i]);
  }
  

  printf("%d",sum);
  return 0;
}


/// confirm df==0 ///
