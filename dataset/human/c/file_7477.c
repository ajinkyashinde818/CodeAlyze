#include <stdio.h>

int main(){

    int i,j,data[10000];
     i=1;
    
    while(1){
	  
	  scanf("%d",&data[i]);
      if (data[i]==0) break;
      ++i;
    }	  
     
       for (j=1;j<i;++j){
	 	printf("Case %d: %d\n",j,data[j]);
	  }
		
	return 0;
}
