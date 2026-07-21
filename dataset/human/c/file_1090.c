#include<stdio.h>

int analysis(char* str){
  int i,answer=0,coefficient=1;

    for(i=0;str[i];i++){
      if('0'<=str[i] && str[i]<='9')
	coefficient=str[i]-'0';
      else{
	switch(str[i]){
	case 'm': 
	  answer=answer+coefficient*1000;
	  break;
	case 'c':
	  answer=answer+coefficient*100;
	  break;
	case 'x':
	  answer=answer+coefficient*10;
	  break;
	case 'i':
	  answer=answer+coefficient;
	  break;
	}
	coefficient=1;
      }
    }
    
    return answer;
}

int main(void){
  int n,i;
  int a,b,c,d,e,f;
  int int_answer;
  char str_a[1024],str_b[1024];

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%s %s",str_a,str_b);
    int_answer=analysis(str_a)+analysis(str_b);
    a=int_answer/1000;
    b=int_answer%1000;
    c=b/100;
    d=b%100;
    e=d/10;
    f=d%10;
    if(2<=a && a<=9)
      printf("%dm",a);
    else if(a==1)
      printf("m");
    if(2<=c && c<=9)
      printf("%dc",c);
    else if(c==1)
      printf("c");
    if(2<=e && e<=9)
      printf("%dx",e);
    else if(e==1)
      printf("x");
    if(2<=f && f<=9)
      printf("%di",f);
    else if(f==1)
      printf("i");
    printf("\n");
  }
    
return 0;
}
