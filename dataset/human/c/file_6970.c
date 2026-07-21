#include <stdio.h>


int main()
{
	int h;
	int w;
	int i;
	int j;

	while(1){

	scanf ("%d %d", &h,&w);

	if(w>300)
		break;
	if(h<1)
		break;

	for( i=0;i<h;i++){

		
		for( j=0;j<w;j++){

			if(i%2!=0&&j%2!=0){
				printf("#");
			}else if(i%2!=0&&j%2==0){
				printf(".");
			}else if(i%2==0&&j%2!=0){
				printf(".");
			}else{
				printf("#");
			}
		}
		
		printf("\n");
		}

	printf("\n");
	if(h&&w==0)
		break;

	}
	return 0;

}
