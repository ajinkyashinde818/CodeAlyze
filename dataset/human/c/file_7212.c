#include<stdio.h>
#include<stdlib.h>
#include<memory.h>
#include<math.h>

int sprInput(char *retstr, char *str, int strnum)
{
	char buf[256]={};
	int h, i, j;

	i = 0;
	for(h=0;h<strnum;h++){
		memset(buf, '\0', sizeof(buf));
		j = 0;
		if (str[i] == '\0') break;
		while(str[i] != ' ' && str[i] != '\n' && str[i] != '\0')
		{
			buf[j] = str[i];
			i++;
			j++;
		}
		i++;
	}
	memcpy(retstr, buf, sizeof(buf));

	return (retstr[0] == '\0' ? 0 : 1);
}

int main(int argc, char *argv[])
{
	int num, i,j,a,b,flg,flgculum;
	char str[256]={};
	char buf[256]={};


	while(1){
		fgets(str, 256, stdin);
		sprInput(buf, str, 1);
		a = atoi(buf);
		sprInput(buf, str, 2);
		b = atoi(buf);

		if(a==0 && b==0){
			break;
		}

		flg = 0;
		flgculum = 0;
		for(i=0; i<a; i++){
			if( 0 == flgculum % 2){
				flg = 0;
			}else{
				flg = 1;
			}
			for(j=0; j<b; j++){
				if(flg == 0){
					printf("#");
					flg = 1;
				}
				else{
					printf(".");
					flg = 0;
				}
			}
			flgculum++;
			printf("\n");
		}
		printf("\n");
	}

	return 0;
}
