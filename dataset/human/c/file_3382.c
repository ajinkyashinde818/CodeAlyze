#include <stdio.h>
#include <string.h>

void sw_str(char* str){
	char tmp = {0};
	int len = strlen(str), i, j;
	
	for(i=0, j=len-1; i<len/2; i++, j--){
		tmp = str[i];
		str[i] = str[j];
		str[j] = tmp;
	}	
}

int main(){
	char*	table[4] = { "maerd", "remaerd", "esare", "resare" };
	char	buff[8] = {0};
    char    s[100000+1] = {0};
	int		idx=0;
	int		flag;

    scanf("%s", s);
	sw_str(s);

	while( idx < strlen(s) ){
		flag = 0;

		for(int i=0; i<4; i++){
			memset( buff, 0x00, sizeof(buff) );
			strncpy( buff, &s[idx], strlen(table[i]) );
			if( strcmp(buff, table[i])==0 ){
				flag=1;
				idx += strlen(table[i]);
				break;
			}
		}
		if( flag == 0 ){ printf("NO\n"); return 0; }
	}
	printf("YES\n");

    return 0;
}
