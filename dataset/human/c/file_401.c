#include <stdio.h>
int main(void){
  int i;
  int len,b;
  char aa[100],bb[100],cc[100];
  int ia,ib,ic;
//  scanf("%s %s",&aa,&bb);
//    printf("aa:%s bb:%s\n",aa,bb);
  scanf("%d %d %d",&ia,&ib);
//    printf("aa:%d bb:%d\n",ia,ib);
	if(ia > 10){
		printf("%d\n",ib);
      
    }
  	else{
		printf("%d\n",ib+100*(10-ia));
    }

  return 0;

}
