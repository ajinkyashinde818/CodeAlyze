#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define LINEMAX 100002

int main(int argc, char *argv[]){

	char line[LINEMAX];

	fgets(line, sizeof(line), stdin);

	char *fromHead = line;
	char *fromTail = &line[strlen(line)-2];
	int   sunukeCnt = 0;

	//printf("fromHead is %c\n", *fromHead);
	//printf("fromTail is %c\n", *fromTail);

	while(1){

		if(fromTail == fromHead || (fromTail+1) == fromHead){
			break;
		}

		if(*fromHead == *fromTail){
			fromHead++;
			fromTail--;
			continue;
		}

		if(*fromHead == 'x'){
			sunukeCnt++;
			fromHead++;
			continue;
		}

		if(*fromTail == 'x'){
			sunukeCnt++;
			fromTail--;
			continue;
		}

		sunukeCnt = -1;
		break;
	}

	printf("%d\n", sunukeCnt);
	return 0;
}
