#include<stdio.h>
#define MAX 200000

int main(){
  int i,n=0,r[MAX];
  int maxvalue=-2000000000;
  //int minivalue;

  scanf("%d",&n);

  for(i=0;i<n;i++){
    scanf("%d",&r[i]);
  }

  int minivalue=r[0];

  for(i=1;i<n;i++){
    if(maxvalue<r[i]-minivalue){
      maxvalue=r[i]-minivalue;
    }
    //else maxvalue=maxvalue;

    if(minivalue>r[i]){
       minivalue=r[i];
       // minivalue=minivalue;
    }
    // else minivalue=r[i];
  }

  printf("%d\n",maxvalue);

  return 0;
}
