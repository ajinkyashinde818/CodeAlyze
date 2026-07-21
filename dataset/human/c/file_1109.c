#include<stdio.h>


int MCXI(char str[]){
  int number;
  int m=0,c=0,x=0,i=0;
  int j;
  for(j=0;str[j]!='\0';j++){
    if(str[j]=='m'){
      if(j==0)m=1;
      else m=str[j-1]-'0';
    }
    if(str[j]=='c'){
      if(j==0)c=1;
      else if(str[j-1]=='m')c=1;
      else c=str[j-1]-'0';
    }
    if(str[j]=='x'){
      if(j==0)x=1;
      else if(str[j-1]=='m'||str[j-1]=='c')x=1;
      else x=str[j-1]-'0';
    }
    if(str[j]=='i'){
      if(j==0)i=1;
      else if(str[j-1]=='m'||str[j-1]=='c'||str[j-1]=='x')i=1;
      else i=str[j-1]-'0';
    }
  }
  number=m*1000+c*100+x*10+i;
  return number;
}


int mcxi(int num){
  int m,c,x,i;
  m=num/1000;
  c=(num%1000)/100;
  x=(num%100)/10;
  i=num%10;

  if(m==1)printf("m");
  else if(m!=0)printf("%dm",m);

  if(c==1)printf("c");
  else if(c!=0)printf("%dc",c);

  if(x==1)printf("x");
  else if(x!=0)printf("%dx",x);

  if(i==1)printf("i");
  else if(i!=0)printf("%di",i);

  printf("\n");

  return 0;
}

int main(void)
{
  int n;
  int j;
 
  scanf("%d",&n);
  char str_1[n][9];
  char str_2[n][9];
  int num[n];

  for(j=0;j<n;j++){
    scanf("%s%s",str_1[j],str_2[j]);
    num[j]=MCXI(str_1[j])+MCXI(str_2[j]);
  }

  for(j=0;j<n;j++){
    mcxi(num[j]);
  }

  return 0;
}
