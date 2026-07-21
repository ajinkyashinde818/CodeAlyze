#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int MCXItoI(char *MCXI,int len);
int ctoi(char c);		//char to integer
void ItoMCXI(int integer,char ans[]);
char itoc(int i);


int main(void) {
	int n;
	scanf("%d",&n);
	int i;
	for(i=0;i<n;i++){
		char MCXI1[8],MCXI2[8];
		scanf("%s %s",MCXI1,MCXI2);
		int num1,num2;
		int len1,len2;
		len1 = strlen(MCXI1);
		len2 = strlen(MCXI2);
		num1 = MCXItoI(MCXI1,len1);
		num2 = MCXItoI(MCXI2,len2);
		char ans[8];
		ItoMCXI(num1+num2,ans);
		printf("%s\n",ans);
	}

	return 0;
}

int MCXItoI(char *MCXI,int len){
	char work;
	int temp = 1;
	int M = 0;
	int C = 0;
	int X = 0;
	int I = 0;
	int i = 0;

	while(i<len){
		work = *(MCXI + i++);
		if('0'<work && work<='9'){
			temp = ctoi(work);
		}
		else{
			switch (work){
			case 'm': M = temp;
					  temp = 1;
					  break;
			case 'c': C = temp;
					  temp = 1;
					  break;
			case 'x': X = temp;
					  temp = 1;
					  break;
			case 'i': I = temp;
					  temp = 1;
					  break;
			}
		}
	}
	int result;
	result = M*1000 + C*100 + X*10 + I;
	return result;
}

int ctoi(char c){
	int i;
	i = c -'0';
	return i;
}

void ItoMCXI(int integer,char ans[]){
	int M = 0;
	int C = 0;
	int X = 0;
	int I = 0;

	M = integer / 1000;
	C = (integer-1000*M) /100;
	X = (integer-1000*M-100*C) / 10;
	I = (integer-1000*M-100*C-10*X);

	int i =0;

	if(M != 0){
		if(M != 1){ans[i++] = itoc(M);}
		ans[i++] ='m';
	}
	if(C != 0){
		if(C!=1){ans[i++] = itoc(C);}
		ans[i++] ='c';
	}
	if(X != 0){
		if(X!=1){ans[i++] = itoc(X);}
		ans[i++] ='x';
	}
	if(I != 0){
		if(I!=1){ans[i++] = itoc(I);}
		ans[i++] ='i';
	}
	ans[i] = '\0';
}

char itoc(int i){
	char c;
	c = i + '0';
	return c;
}
