#include <stdio.h>
#include <string.h>

int main(void) {
	char s[100001], tmp[100001];
	int i, j, pos, slen, len;
	int flag;
	char str[4][10] = {"dream", "dreamer", "erase", "eraser"};
	
	scanf("%s", s);
	
	// str[i]の文字を反転
	for (i = 0; i < 4; i++) {
		len = strlen(str[i]); // str[i]の文字数を取得
		for (j = 0; j < len; j++) tmp[j] = str[i][len - 1 - j];
		tmp[len] = '\0';
		strcpy(str[i], tmp);
	}
	
	slen = strlen(s); // sの文字数を取得
	for (i = 0; i < slen; i++) tmp[i] = s[slen - 1 - i];
	strcpy(s, tmp);
	
	pos = 0;
	while (1) {
		flag = 1;
		
		for (i = 0; i < 4; i++) {
			len = strlen(str[i]);
			if (slen - pos < len) continue; // 配列のオーバーアクセスを防ぐ
			
			// str[i]のどれかと一致すれば
			if (strncmp(&s[pos], str[i], len) == 0) {
				pos += len;
				flag = 0;
			}
		}
		
		if (flag) break;
	}
	
	if (pos == slen) puts("YES");
	else puts("NO");
	
	return 0;
}
