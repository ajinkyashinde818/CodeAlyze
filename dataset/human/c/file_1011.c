#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main(){

	int n,k[100],len;
	char s[100];
	int i,j;


	while(1){
		scanf("%d",&n);

		if(n == 0){

			exit(0);
		}

		for(i=0; i < n; i++){

			scanf("%d",&k[i]);
		}

		scanf("%s",s);

		for(i = 0; i < strlen( s ); i++){

			for(j = 0;j < k[i%n];j++){
				
				if(s[i] == 'a'){
					s[i] = 'Z';
				}
				else if(s[i] == 'A'){
					s[i] = 'z';
				}
				else{
					s[i]--; 
				}

			}

		}

		printf("%s\n",s);
	}

}
