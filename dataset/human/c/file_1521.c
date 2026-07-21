#include<stdio.h>

int main(void){
  char buff[1000];
  char x,y;
  int nx,ny;

  fgets(buff,1000,stdin);
  sscanf(buff,"%c %c",&x,&y);


  if(x=='A'){
    nx=10;
  }else if(x=='B'){
    nx=11;
  }else if(x=='C'){
    nx=12;
  }else if(x=='D'){
    nx=13;
  }else if(x=='E'){
    nx=14;
  }else if(x=='F'){
    nx=15;
  }

  if(y=='A'){
    ny=10;
  }else if(y=='B'){
    ny=11;
  }else if(y=='C'){
    ny=12;
  }else if(y=='D'){
    ny=13;
  }else if(y=='E'){
    ny=14;
  }else if(y=='F'){
    ny=15;
  }


  if(nx>ny){
    printf(">");
  }else if(nx<ny){
    printf("<");
  }else if(nx==ny){
    printf("=");
  }

  return 0;
}
