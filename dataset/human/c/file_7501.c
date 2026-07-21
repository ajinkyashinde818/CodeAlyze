#include <stdio.h>

#define  MAX 10000

int main(int argc, char *argv[]) {
	
	int in[MAX] = { 0 };
	int i = 0;
	
	do{
		fscanf(stdin, "%d", &in[i]);
		i++;
	}while(in[i-1] != 0);
	
	i = 0;
	while(in[i] != 0) {
		fprintf(stdout, "Case %d: %d\n", i+1, in[i]);
		i++;
	}
	
	return 0;
	
}
