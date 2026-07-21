#include<stdio.h>
int main(){
int h,w,i,j,flag=1;
char a[51][51]={'0'};
scanf("%d %d",&h,&w);
for(i=0;i<h;i++)
{
  scanf("%s",a[i]);
}
for(i=0;i<h;i++)
{
  for(j=0;j<w;j++)
  {
    if(a[i][j]=='#')
    {
      if((i==0||a[i-1][j]!='#')&&(j==0||a[i][j-1]!='#')&&(a[i+1][j]!='#')&&(a[i][j+1]!='#'))flag=0;
    }
  }
}
if(flag)printf("Yes");
else printf("No");
}
