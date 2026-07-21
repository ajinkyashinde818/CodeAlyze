#include <stdio.h>
int main(){
  int h,w,n,i,j,f=1,b=0,a=0,t=-1,d[310][310]={};
  char s[310][310];
  scanf("%d %d %d",&h,&w,&n);
  for(i=0;i<h;i++)
    scanf("%s",s[i]);
  for(i=0;i<h;i++){
    b=a=a+f;
    f=0;
    for(j=0;j<w;j++){
      if(s[i][j]=='#'){
	      if(f==1) a++;
	      f=1;
      }
      d[i][j]=a;
    }
    if(f==1&&t==-1) t=i;
    if(f==0){
      for(j=0;j<w;j++)
        d[i][j]=d[i-1][j];
    }
  }
  for(i=0;i<w;i++){
    for(j=0;j<t;j++)
      d[j][i]=d[t][i];
  }
  for(i=0;i<h;i++){
    for(j=0;j<w;j++)
      printf("%d%c",d[i][j],j+1==w?'\n':' ');
  }
  return 0;
}
