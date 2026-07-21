#include<stdio.h>
#include<string.h>
int main(){
  int n,i,j,a;
  double z=0;
  char s[10];
  char x[16]={"0123456789abcdef"};
  char b[16][8]={"0000","0001","0010","0011","0100","0101","0110","0111",
		 "1000","1001","1010","1011","1100","1101","1110","1111"};
  scanf("%d",&n);
  //printf("%f\n",1<<-1);
  while(n--){
    char d[40]={0};
    scanf("%s",s);
    for(i=a=0;i<8;i++){
      for(j=0;x[j]-s[i];j++);
      strcat(d,b[j]);
    }
    if(d[0]=='1')printf("-");
    for(i=1;i<32;i++)a=a*2+d[i]-'0';
    z=a/128.0-a/128;
    printf("%d.",a/128);
    if(z==0)printf("0");
    for(;z;z-=a){
      z*=10;
      a=z;
      printf("%d",a);
    }
    printf("\n");    
  }
  return 0;  
}
