#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N (100000 + 1)

// beginsWith 
// srcがstrから始まる文字列かどうかを調べる
int beginsWith(char* src, char* str){
	int len_of_str = strlen(str);
	int i;
	if(strlen(src) < len_of_str)
		return 0;

	for(i=0; i < len_of_str; i++){
		if(*(src + i) != *(str + i)){
			return 0;
		}
	}
	return 1;

}

int inductive_search(char* S, int i){
	int L = strlen(S);
	//printf("%s\n",S+i);
	if(i == L) 
		return 1;
	else if(beginsWith(S+i, "dreamer")){
		return (inductive_search(S, i+5) || inductive_search(S, i+7));
	}else if(beginsWith(S+i, "dream")){
		return inductive_search(S, i+5);
	}else if(beginsWith(S+i, "eraser")){
		return (inductive_search(S, i+6));
	}else if(beginsWith(S+i, "erase")){
		return inductive_search(S, i+5);
	}else{
		return 0;
	}
}

int main(){

	char *str;
	str = (char*)malloc(sizeof(char) * N);

	scanf("%s", str);

	if(inductive_search(str, 0)){
		printf("YES\n");
	}else{
		printf("NO\n");
	}


	return 0;

}
