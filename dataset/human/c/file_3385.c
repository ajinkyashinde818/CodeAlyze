#include <stdio.h>
#include <string.h>

void reverse(char *str){
	int len = strlen(str);
	for(int i=0; i < len / 2; i++) {
		char temp = str[i];
		str[i] = str[len-1-i];
		str[len-1-i] = temp;
	}
}

int main(void){
	int len, beAble;
	char str[100001];

	unsigned char candsLen[4] = {5, 7, 5, 6};
	char cands[4][8] = {
		{"dream"},
		{"dreamer"},
		{"erase"},
		{"eraser"},
	};

	scanf("%s", str);

	reverse(str);
	for(int i=0; i < 4; i++) {
		reverse(cands[i]);
	}

	len = strlen(str);
	for(int i=0; i < len;) {
		beAble = 0;
		for(int j=0; j < 4; j++) {
			if(!strncmp(str+i, cands[j], candsLen[j])) {
				beAble = 1;
				i += candsLen[j];
				break;
			}
		}
		if(!beAble) {
			printf("NO");
			return 0;
		}
	}
	printf("YES");

	return 0;
}
