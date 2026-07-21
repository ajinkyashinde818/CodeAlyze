#include<stdio.h>
int main(){
  int n ,cnt=0;
  while( scanf( "%d",&n ) != EOF ){
    if( n == 0 ){
      break;
    }
    
    while( n != 1 ){
      if( n % 2 == 0 ){
	n = n / 2;
	cnt++;
      }
      else{
	n = n * 3;
	n++;
	cnt++;
      }
    }
    
    printf( "%d\n",cnt );
    cnt = 0;
  }

  return 0;
}
