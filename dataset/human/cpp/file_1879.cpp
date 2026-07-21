#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>

using namespace std;

int main(){

	int Q,p,ans_seisu;
	double seisu[24],syosu[8],ans_syosu;

	for(int i = 0; i <= 23; i++){
		seisu[i] = pow(2,i);
	}

	for(int i = 1; i <= 7; i++){
		syosu[i] = 1.0/pow(2,i);
	}

	char buf[9],work[33];

	scanf("%d",&Q);

	for(int loop = 0; loop < Q; loop++){
		scanf("%s",buf);

		p = 0;

		for(int i = 0;buf[i] != '\0';i++){
			switch(buf[i]){
			case '0':
				work[p++] = '0',work[p++] = '0',work[p++] = '0',work[p++] = '0';
				break;
			case '1':
				work[p++] = '0',work[p++] = '0',work[p++] = '0',work[p++] = '1';
				break;
			case '2':
				work[p++] = '0',work[p++] = '0',work[p++] = '1',work[p++] = '0';
				break;
			case '3':
				work[p++] = '0',work[p++] = '0',work[p++] = '1',work[p++] = '1';
				break;
			case '4':
				work[p++] = '0',work[p++] = '1',work[p++] = '0',work[p++] = '0';
				break;
			case '5':
				work[p++] = '0',work[p++] = '1',work[p++] = '0',work[p++] = '1';
				break;
			case '6':
				work[p++] = '0',work[p++] = '1',work[p++] = '1',work[p++] = '0';
				break;
			case '7':
				work[p++] = '0',work[p++] = '1',work[p++] = '1',work[p++] = '1';
				break;
			case '8':
				work[p++] = '1',work[p++] = '0',work[p++] = '0',work[p++] = '0';
				break;
			case '9':
				work[p++] = '1',work[p++] = '0',work[p++] = '0',work[p++] = '1';
				break;
			case 'a':
				work[p++] = '1',work[p++] = '0',work[p++] = '1',work[p++] = '0';
				break;
			case 'b':
				work[p++] = '1',work[p++] = '0',work[p++] = '1',work[p++] = '1';
				break;
			case 'c':
				work[p++] = '1',work[p++] = '1',work[p++] = '0',work[p++] = '0';
				break;
			case 'd':
				work[p++] = '1',work[p++] = '1',work[p++] = '0',work[p++] = '1';
				break;
			case 'e':
				work[p++] = '1',work[p++] = '1',work[p++] = '1',work[p++] = '0';
				break;
			case 'f':
				work[p++] = '1',work[p++] = '1',work[p++] = '1',work[p++] = '1';
				break;
			}
		}

		work[p] = '\0';

		ans_seisu = 0;
		for(int i = 1; i <= 24; i++){
			if(work[i] == '1'){
				ans_seisu += seisu[24-i];
			}
		}

		ans_syosu = 0;
		for(int i = 25; i <= 31; i++){
			if(work[i] == '1'){
				ans_syosu += syosu[i-24];
			}
		}

		if(work[0] == '1')printf("-");

		printf("%d",ans_seisu);

		if(ans_syosu == 0){
			printf(".0\n");
		}else{
			printf(".");

			for(int i = 1; i <= 7; i++){
				ans_syosu *= 10;
				printf("%.0f",floor(ans_syosu));

				ans_syosu -= floor(ans_syosu);
				if(ans_syosu == 0)break;
			}
			printf("\n");
		}
	}

	return 0;
}
