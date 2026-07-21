#include <stdio.h>

//FILE * in = freopen("input.txt", "r", stdin);

int n;
int key[100];
char temp[1000];

char getChar(char c, int key){
	int code = 0;
	if('A' <= c && c <= 'Z') {
		code = c - 'A';
	}
	else if('a' <= c && c <= 'z'){
		code = c - 'a' + 26;
	}

	code -= key;
	if(code < 0) code += 52;

	if(code < 26) {
		return code + 'A';
	}
	return code + 'a' - 26;
}

void process(){
	int kp = 0;
	for(int i = 0; temp[i] ; i++){
		temp[i] = getChar(temp[i], key[kp++]);
		kp %= n;
	}
}

int main() {
	while(true){
		scanf("%d", &n);
		if(n == 0) break;
		for(int i = 0; i < n; i++) {
			scanf("%d", &key[i]);
		}
		gets(temp);
		gets(temp);
		process();
		printf("%s\n", temp);
	}
	return 0;
}
