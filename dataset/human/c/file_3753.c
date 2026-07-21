#include<stdio.h>
#define BUFSIZE 10000
int main(void){
	int reminder[BUFSIZE]={0};
	long a,b;
	int i;
	int m=0;
    scanf("%d %d",&a,&b);
    for(i=1;i<=a;i++){
		if(a%i==0){
			reminder[m]=i;
							
			m++;
		}
	}
	int n=0;
	int N_reminder[BUFSIZE]={0};
		for(int m=0;m<BUFSIZE;m++){
		    if(reminder[m]==0){
				break;
			}    
				if(b%reminder[m]==0){
					N_reminder[n]=reminder[m];
					n++;
				}
		}
long gcd;		
for(int j=0;j<BUFSIZE;j++){
	if(N_reminder[j]==0){
		gcd=N_reminder[j-1];
		break;
	}
}

printf("%ld",a/gcd*b/gcd*gcd);			
		
			

}
