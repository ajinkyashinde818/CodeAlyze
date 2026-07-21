#include <limits.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <math.h>

#define もし if(
#define そうでなくてもし }else if(
#define ならば ){
#define そうでないならば }else{
#define を実行する }

#define が ==
#define を =
#define とする

#define 文字列を読み込む(s) scanf("%s", s)
#define 整数を読み込む(x) int x; scanf("%d", &x)
#define 文字を読み込む(c) char c; scanf(" %c", &c)

#define 文字列を書き出す(s) printf("%s", (s))
#define 文字を書き出す(c) printf("%c", (c))
#define 改行する putchar(10)

#define 文字列の長さ(s) (strlen(s))

typedef int 整数;
typedef char 文字;

int main(void){
	文字 s[500001];
	文字列を読み込む(s+200000);
	整数 l を 200000 とする;
	整数 r を 200000+文字列の長さ(s+200000)とする;
	整数 f を 1 とする;

	整数を読み込む(q);
	整数 i;
	for(i=0; i<q; i++){
		整数を読み込む(Q);
		もし Q が 1 ならば
			もし f が 1 ならば
				f を 2 とする;
			そうでないならば
				f を 1 とする;
			を実行する
		そうでないならば
			整数を読み込む(F);
			文字を読み込む(c);
			もし F が f ならば
				s[--l] を c とする;
			そうでないならば
				s[r++] を c とする;
			を実行する
		を実行する
	}
	もし f が 1 ならば
		s[r] を 0 とする;
		文字列を書き出す(s+l);
		改行する;
	そうでないならば
		for(i=r-1; i>=l; i--){
			文字を書き出す(s[i]);
		}
		改行する;
	を実行する
}
