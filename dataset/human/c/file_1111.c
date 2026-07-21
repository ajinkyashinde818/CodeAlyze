#include <stdio.h>

int decode(char s[10]){
  int i,j;
  int r=0;
  for( i=0;s[i]!='\0';i++){
    if( '2'<=s[i] && s[i]<='9' ){
      s[i]-='0';
      continue;
    }
    j=i-1;
    if( s[i]=='m' ){
      if( i==0 ) r+=1000;
      else r+= s[j]*1000;
    }else if( s[i]=='c' ){
      if( i==0 || s[j]=='m' ) r+=100;
      else r+= s[j]*100;
    }else if( s[i]=='x' ){
      if( i==0 || s[j]=='m'||s[j]=='c' ) r+=10;
      else r+= s[j]*10;
    }else{
      if( i==0||s[j]=='m'||s[j]=='c'||s[j]=='x' ) r+=1;
      else r+=s[j];
    }

  }
  return r;
}

int main(void){ 
  int n,lp;
  char s1[10],s2[10];
  int j,sum;

  scanf("%d ",&n);
  for( lp=0;lp<n;lp++ ){
    scanf("%s %s ",s1,s2);

    sum = decode(s1)+decode(s2);
    if( (j=sum/1000)>0 ){
      if( j==1 ) printf("m");
      else       printf("%dm",j); sum = sum%1000;
    }
    if( (j=sum/100)>0 ){
      if( j==1 ) printf("c");
      else       printf("%dc",j); sum = sum%100;
    }
    if( (j=sum/10)>0 ){
      if( j==1 ) printf("x");
      else       printf("%dx",j); sum = sum%10;
    }
    if( sum>0 ){
      if( sum==1 ) printf("i");
      else         printf("%di",sum);
    }
    printf("\n");
  }
  return 0;
}
