#include <stdio.h>
int  main()
{
  int a,cou;
  while(1){
    scanf("%d",&a);
    if(a==0)break;
    cou=0;
    while(a!=1){
      if(a%2==0){
	a=a/2;
	cou++;
      } else {
	a=a*3+1;
	cou++;
      }
    }
    printf("%d\n",cou);
  }
  return 0;
}
