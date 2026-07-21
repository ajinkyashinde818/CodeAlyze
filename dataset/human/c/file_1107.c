/*No.1137 Numeral System*/

#include <stdio.h>

void print_mcxi(int s);
int mcxi_integer(char *array);
int integer(char c);

int main(void){

  int i;
  int n;
  int sum=0;

  scanf("%d",&n);

  for(i=0;i<n;i++){

    char num_1[10]={0};
    int  sum_1=0;
    char num_2[10]={0};
    int sum_2=0;

    scanf("%s%s",num_1,num_2);

    sum_1=mcxi_integer(num_1);
    sum_2=mcxi_integer(num_2);

    sum=sum_1+sum_2;

    print_mcxi(sum);
 }

  return 0;
}

void print_mcxi(int s){
  int m=0;
  int c=0;
  int x=0;
  int i=0;

  if(s>999 && s<10000){
    m=s/1000;
    c=(s-m*1000)/100;
    x=(s-m*1000-c*100)/10;
    i=s-m*1000-c*100-x*10;
  }
  else if(s>99 && s<1000){
    c=s/100;
    x=(s-c*100)/10;
    i=s-c*100-x*10;
  }
  else if(s>9 && s<100){
    x=s/10;
    i=s-x*10;
  }
  else if(s>0 && s<10){
    i=s;
  }

  if(m==1){printf("m");}
  if(m>1){printf("%dm",m);}
  if(c==1){printf("c");}
  if(c>1){printf("%dc",c);}
  if(x==1){printf("x");}
  if(x>1){printf("%dx",x);}
  if(i==1){printf("i");}
  if(i>1){printf("%di",i);}

  printf("\n");
}

int mcxi_integer(char *array){

  int j;
  int sum=0;

  for(j=0;array[j]!='\0';j++){
    
    if(j==0){
      switch(array[j]){
      case 'm': sum+=1000;break;
      case 'c': sum+=100;break;
      case 'x': sum+=10;break;
      case 'i': sum+=1;break;
      default: break;
      }
    }
    else if(j>0){
      switch(array[j]){
      case 'm': sum+=(integer(array[j-1])*1000);break;
      case 'c': sum+=(integer(array[j-1])*100);break;
      case 'x': sum+=(integer(array[j-1])*10);break;
      case 'i': sum+=(integer(array[j-1])*1);break;
      default : break;
      } 
    }
      
  }

  return sum;

}
  
int integer(char c){

  int m;

  switch(c){
  case '2': m=2;break;
  case '3': m=3;break;
  case '4': m=4;break;
  case '5': m=5;break;
  case '6': m=6;break;
  case '7': m=7;break;
  case '8': m=8;break;
  case '9': m=9;break;
  default : m=1;break;
  }

  return m;
}
