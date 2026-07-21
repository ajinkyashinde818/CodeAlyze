#include<stdio.h>
#include<string.h>

void revStr(char* str){
  int size = strlen(str);
  int i,j;
  char tmp = {0};
	
  for(i = 0, j = size - 1; i < size / 2; i++, j--){
    tmp = str[i];
    str[i] = str[j];
    str[j] = tmp;
  }
	
  return;	
}

int main()
{
  char s[300000], sento[300000], matsu[300000];
  int q, rev = 0, i;

  scanf("%s", s);
  scanf("%d", &q);

  for (; q > 0; q--) {
    int t;
    scanf("%d", &t);
    if (t == 1) {	// 文字列反転
      rev++;
    } else if (t == 2) {
      int f;
      char c[2];
      scanf("%d %s", &f, c);
      if (f == 1) {
	if (rev % 2 == 0) {	// 反転してない
	  // 先頭に追加
	  strcat(sento, c);
	} else {		// 反転している
	  // 末尾に追加
	  strcat(matsu, c);
	}
      } else if (f == 2) {
	if (rev %2 == 0) {	// 反転してない
	  // 末尾に追加
	  strcat(matsu, c);
	} else {
	  // 先頭に追加
	  strcat(sento, c);
	}
      }
    }
  }
  // 最後に結合
  if (rev % 2 == 0) {
    revStr(sento);
    strcat(sento, s);
    strcat(sento, matsu);
    printf("%s\n", sento);
  } else {
    revStr(matsu);
    revStr(s);
    strcat(matsu, s);
    strcat(matsu, sento);
    printf("%s\n", matsu);
  }
  return 0;
}
