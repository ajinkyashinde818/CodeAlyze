#include <stdio.h>
int noa(){
	char s[32];
	int a=0,b=0,c=0;
	scanf("%s\n", s);
	for(int i =0;i<strlen(s);i++){
	   // printf("%c[%d][%d][%d]\n",s[i],a,b,c );
		if(s[i] == 'a'){
			a++;
			continue;
		}
		if(s[i] == 'b'){
			b++;
			continue;
		}
		if(s[i] == 'c'){
			c++;
			continue;
		}
	}
	if(a == b && b == c){
		printf("%s\n","Yes" );
		return 0;
	}else{
		printf("%s\n","No" );
		return 0;
	}
}

int main(void){
	// Your code here!
	noa();
	return 0;

}
