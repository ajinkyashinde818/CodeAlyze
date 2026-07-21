#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {

char inp[100];
int i;
int year;
double nm;
int c,j,count;
char str[100]={'\0'};
char *ln;

fgets(str, 100, stdin); // 入力："123456\n"
ln = strchr(str, '\n'); /* 改行文字を検索 */
if (ln != NULL) { /* 改行が読み取られていたかどうか */
   *ln = '\0';    /* 改行文字を終端文字に置き換える */
}
else {            /* 入力ストリーム上に文字が残ってる場合 */
   while (1) {    /* 改行文字が読み取られるまで空読みする */
       c = getchar();
      if (c == '\n' || c == EOF) break;
   }
}

//printf("%s\n",str);



//double sum=0;

//sscanf(str, "%d", &year);
//printf("%d\n",year);

//for(i=1;i<=year;i++){




//fgets(str, 100, stdin); // 入力："123456\n"
//ln = strchr(str, '\n'); /* 改行文字を検索 */
//if (ln != NULL) { /* 改行が読み取られていたかどうか */
//   *ln = '\0';    /* 改行文字を終端文字に置き換える */
//}
//else {            /* 入力ストリーム上に文字が残ってる場合 */
//   while (1) {    /* 改行文字が読み取られるまで空読みする */
//       c = getchar();
//      if (c == '\n' || c == EOF) break;
//   }
//}

//printf("%s\n",str);



int a,b;

 sscanf(str, "%d %d %d", &a, &b, &c);

//printf("%d\n",a);
//printf("%d\n",b);
//printf("%d\n",c);

int d;
int e=0;

if(a>b){
	for(i=0;i<a;i++){
	if(a%(i+1)==0 && b%(i+1)==0){
//		printf("%d\n",i+1);
		e=e+1;
//		if(e==c){
//		printf("%d\n",i+1);
//		break;}

		}
	}
}
else {
	for(i=0;i<b;i++){
	if(a%(i+1)==0 && b%(i+1)==0){
//		printf("%d\n",i+1);
		e=e+1;
//		if(e==c){
//		printf("%d\n",i+1);
//		break;}
		}
}
}



int f=0;

if(a>b){
	for(i=0;i<a;i++){
	if(a%(i+1)==0 && b%(i+1)==0){
//		printf("%d\n",i+1);
		f=f+1;
		if(f==e-c+1){
		printf("%d\n",i+1);
		break;}

		}
	}
}
else {
	for(i=0;i<b;i++){
	if(a%(i+1)==0 && b%(i+1)==0){
//		printf("%d\n",i+1);
		f=f+1;
		if(f==e-c+1){
		printf("%d\n",i+1);
		break;}
		}
}
}







//		printf("%d\n",e);


    return 0;
}
