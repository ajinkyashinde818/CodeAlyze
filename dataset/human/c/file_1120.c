#include <stdio.h>

int main () {


	int dataset=0;
	int dataset_num=0;
	int input=0;
	int count=0;
	int number=1;
	int mul=1;

	int result1=0;
	int result2=0;
	char f_result=0;

	char bef[10]={};
	char aft[10]={};


	scanf("%d",&dataset);
	dataset_num = dataset;
	count=0;

	while( dataset != 0 ){
		scanf("%s %s",bef,aft);

		result1=0;
		result2=0;
		f_result=0;
		count=0;
		number=1;

		
		while(1){
			mul = 1;

			if (bef[count] >= '2' && bef[count] <= '9'){
				number = bef[count]-48;
				count++;
			}

			if(bef[count] == 'm'){
				mul = mul * 1000;
			}	
			else if(bef[count] == 'c'){
				mul = mul * 100;
			}
			else if(bef[count] == 'x'){
				mul = mul * 10;	
			}	
			else if(bef[count]== 'i'){
					
			}

			result1 += mul * number;
			//printf("%d\n",result1 );
			number = 1;
			count++;

			if(bef[count] == '\n' || bef[count]== ' ' || bef[count]== '\0'){
				//printf("finish\n");
				break;
			}
		}



		//printf("result1:%d\n",result1 );
		count=0;
		while(1){
			mul = 1;

			if (aft[count] >= '2' && aft[count] <= '9'){
				number = aft[count]-48;
				count++;
			}

			if(aft[count] == 'm'){
				mul = mul * 1000;
			}	
			else if(aft[count] == 'c'){
				mul = mul * 100;
			}
			else if(aft[count] == 'x'){
				mul = mul * 10;	
			}	
			else if(aft[count]== 'i'){
					
			}

			result2 += mul * number;
			//printf("%d\n",result2 );
			number = 1;
			count++;

			if(aft[count] == '\n' || aft[count]== ' ' || aft[count]== '\0'){
				//printf("finish\n");
				break;
			}
		}
		//printf("result2:%d\n", result2);


		result1 += result2;
		mul =1000;
		number=1;
		//printf("%d\n",result1 );
		while(1){

			
			if( (int)(result1 / mul) == 0){
				mul = mul/10;
				continue;
			}
			else{
				//printf("mul:%d\n",mul);
				number = result1/mul;

				if( number != 1){
					f_result = number+48;
					printf("%c",f_result );
				}
				

				result1 -= number * mul;



				if(mul==1000){
					printf("m");
				}
				else if(mul==100){
					printf("c");
				}
				else if(mul == 10 ){
					printf("x");
				}

				

				if(mul==1){
					printf("i\n");
					break;
				}
				if(result1 == 0){
					printf("\n");
					break;
				}
				mul = mul/10;
			}
			

		}



	dataset--;
	input++;
	}


	return 0;
}
