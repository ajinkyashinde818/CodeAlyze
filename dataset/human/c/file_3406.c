#include <stdio.h>
#include <string.h>
char str[100000];
int count=0;
void change(int);
int main(void){
    scanf("%s",str);
    change(0);
    if(count>0) printf("YES\n");
    else printf("NO\n");
    return 0;
}
void change(int begin){
	char s1[10]="";
	char s2[10]="";
	char s3[10]="";
	int i;
	if(begin==strlen(str)) count++;
	if(begin>strlen(str)-4) return;
	for(i=0;i<5;i++)
		s1[i] = str[begin+i];
	for(i=0;i<6;i++)
	    s2[i] = str[begin+i];
	for(i=0;i<7;i++)
	    s3[i] = str[begin+i];
	if(strcmp(s1,"dream")==0||strcmp(s1,"erase")==0)
	    change(begin+5);
	if(strcmp(s2,"eraser")==0)
	    change(begin+6);
	if(strcmp(s3,"dreamer")==0)
	    change(begin+7);
    return;
}
