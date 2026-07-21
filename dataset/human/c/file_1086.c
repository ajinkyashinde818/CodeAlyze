#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
int n;
char a[10];
char b[10];
int integer(char c){
	int integer;
	if(c=='m')
	integer=1000;
	if(c=='c')
	integer=100;
	if(c=='x')
	integer=10;
	if(c=='i')
	integer=1;
	return integer;
}
int change(char d[100]){
	int changed=0;
	for(int i=0;i<strlen(d);i+=1){
		if((d[i] >= 50) && (d[i] <= 57)){
			int j=i+1;
			changed+=(d[i]-48)*integer(d[j]);   //文字列要转换成阿斯卡码
			i++;
		}
		else {
			changed+=integer(d[i]);
		}
	}
	return changed;
	
}

int main(){
	int sum;
	scanf("%d",&n);
	while (n--) {
		scanf("%s",a);
		scanf("%s",b);
		sum=change(a)+change(b);
		//printf("%d",sum);
		int a=sum;
		int digit=0;
		while (a) {
				a/=10;
				digit++;
			}
			int i=0,x=digit;
			char cb[100]={0};
			int q=0;


		while (digit--) {
				int a=(pow(10.0, x));
				int b=(pow(10.0,x-1));
				q=sum%a/b;
				 if (q==1) {
					if (x==1) {
						cb[i]='i';
					}
					if (x==2) {
						cb[i]='x';
					}
					if (x==3) {
						cb[i]='c';
					}
					if (x==4) {
						cb[i]='m';
					}
					
				}
				else if(q>1){
					cb[i]=(q+48);
					if (x==1) {
						cb[i+1]='i';
					}
					if (x==2) {
						cb[i+1]='x';
					}
					if (x==3) {
						cb[i+1]='c';
					}
					if (x==4) {
						cb[i+1]='m';
					}
					i++;

					
				}
				if (q!=0) {
					i++;
				}
				x--;
				
			}
			printf("%s\n",cb);

				
		
	}
	return 0;
	
}
