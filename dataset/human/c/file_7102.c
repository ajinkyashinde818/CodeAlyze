#include	<stdio.h>
int	main(void)
{
	int H, W, cycle1=1, cycle2;
	while(1){
	    scanf(" %d %d", &H, &W);
	    if(H==0 && W==0) return 0;
	    else if(H<1 || W<1 || W>300) continue;

	    while(cycle1<=H){
		    cycle2 = 1;
		    if(cycle1%2==0){
		       while(cycle2<=W){
		    	  switch(cycle2%2){
		             case 1: printf(".");
		                    break;
		             case 0: printf("#");
		                    break;
		          };
		    	  cycle2++;
		       }

		    }else{
		    	while(cycle2<=W){
		    	   switch(cycle2%2){
		    	      case 0: printf(".");
		    		         break;
		    		  case 1: printf("#");
		    		         break;
		           };
		    	   cycle2++;
		        }
		    }

		 puts("");
		 cycle1++;
	    }
	    puts("");
	    cycle1=1;
	}
	return	0;
}
