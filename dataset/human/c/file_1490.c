#include "stdio.h"

int main(int argc, char const *argv[])
{
	char value0,value1;
	scanf("%c %c",&value0,&value1 );
	
	if((int)value0>(int)value1){
		printf(">\n");
	}
	else if((int)value0<(int)value1){
		printf("<\n");
	}
	else if((int)value0==(int)value1){
		printf("=\n");
	}

	return 0;
}
