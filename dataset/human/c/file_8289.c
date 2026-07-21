#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void inp_str(int*);


int main(void) {

int N,K;
char S[100];
char out[100];

scanf("%d",&N);

scanf("%s",S);
scanf("%d",&K);


/*printf("%d\n",N);
printf("%s\n",S);
printf("%d\n",K);*/


int i;
for(i=0;i<N;i=i+1){
if(S[i]==S[K-1]){
	out[i]=S[i];
}else{
	out[i]='*';
}
}
out[N]=S[N];

printf("%s\n",out);


//printf("%d\n",M);

//printf("%d\n",C);




/*

if(flag==1) {
	printf(":(\n");
}else{
printf("Yay!\n");
} 

*/                       
    return 0;
}


void inp_str(int instr[]){
char *ptr;
int z,i,count;
char str[100]={'\0'};
char *ln;

fgets(str, 100, stdin); // 入力："123456\n"
ln = strchr(str, '\n'); /* 改行文字を検索 */
if (ln != NULL) { /* 改行が読み取られていたかどうか */
   *ln = '\0';    /* 改行文字を終端文字に置き換える */
}
else {            /* 入力ストリーム上に文字が残ってる場合 */
   while (1) {    /* 改行文字が読み取られるまで空読みする */
       z = getchar();
      if (z == '\n' || z == EOF) break;
   }
}
	count=0;
    ptr = strtok(str, " ");
    i = atoi(ptr);
    instr[count]=i;
    count=count+1;
    // 2回目以降
    while(ptr != NULL) {
        // strtok関数により変更されたNULLのポインタが先頭
        ptr = strtok(NULL, " ");
        // ptrがNULLの場合エラーが発生するので対処
        if(ptr != NULL) {
		    i = atoi(ptr);
    instr[count]=i;
    		count=count+1;
        }
    }
}
