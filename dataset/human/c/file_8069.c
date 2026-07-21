#include <stdio.h>
#include <inttypes.h>

int64_t koenai_saidai(int64_t start, int64_t limit, int64_t delta) {
	if (delta > 0) {
		return start + ((limit - start) / delta) * delta;
	} else {
		int64_t d = -delta;
		return start - ((start - limit) / d) * d;
	}
}

int main(void) {
	int T;
	int nakagawasyouko;
	if (scanf("%d", &T) != 1) return 1;
	for (nakagawasyouko = 0; nakagawasyouko < T; nakagawasyouko++) {
		int64_t A, B, C, D;
		if (scanf("%" SCNd64 "%" SCNd64 "%" SCNd64 "%" SCNd64, &A, &B, &C, &D) != 4) return 1;
		if (C < B - D || A < B || D < B) {
			puts("No");
		} else {
			int64_t right = B >= C ? B : C;
			int64_t ng_left = B - D - 1, ng_right = C + 1;
			/* 最初にBまたはCを切った時 */
			int64_t start = koenai_saidai(A, right, -B) - B;
			int64_t D_mod_B = D % B;
			if (ng_right <= start) {
				puts("No");
			} else if (D_mod_B == 0) {
				/* 着地位置が変わらない */
				puts(D_mod_B <= ng_left || ng_right <= D_mod_B ? "No" : "Yes");
			} else {
				int64_t zure = B % D_mod_B;
				int64_t diff, saidai;
				if (zure == 0) {
					diff = D_mod_B;
				} else {
					int64_t asumi = D_mod_B, iguti = zure;
					while (iguti > 0) {
						int64_t ogura = asumi % iguti;
						asumi = iguti;
						iguti = ogura;
					}
					diff = asumi;
				}
				saidai = koenai_saidai(start, right - 1, diff);
				if (ng_right <= saidai) {
					puts("No");
				} else {
					int64_t next = saidai + diff;
					int64_t next_next = next - B;
					puts(next_next <= ng_left ? "No" : "Yes");
				}
			}
		}
	}
	return 0;
}

/*

NGになる場合とは？

昼の時点でジュースがB本未満
・最初から足りない A<B
・補充判定に引っかからず足りない 在庫<B && 在庫>C
・補充しても足りない 在庫<=C && 在庫+D<B

パターン1 (右にNGエリアあり : C < B - 1)
     B-D    C     B
     |      |     |
xxxxxooooooooxxxxxoooooo

パターン2 (右にNGエリアなし : C <= B - 1)
     B-D    B     C
     |      |     |
xxxxxooooooooooooooooooo

パターン3 (絶望 : C < B - D (C + D < B))
     C      B-D   B
     |      |     |
xxxxxxxxxxxxxxxxxxoooooo

B本ずつ買っていく → Bの倍数を引く
最初にBまたはCを切った時注目！
この時、max(B,C)-B <= 在庫 < max(B,C) になっている
在庫がD増える → またBの倍数を引く → D mod B だけ足せばよい
パターン3のとき、死亡確定
パターン1のとき、max(B,C) = B
  D mod B を足していって、B以上になる直前に注目！
    Cを超えていたら、失格
    Cを超えていなかったら…？
パターン2のとき、max(B,C) = C
  D mod B を足していって、C以上になったらBを引く

パターン1・2共通
  Bを引くと、B mod (D mod B)だけ位相がずれる
  結局、gcd(D mod B, B mod (D mod B)) 個おきの列になる
  最初の着地位置から考えて、この列に引っかからなければ右のNGエリアはセーフ
  左のNGエリアは、この列で行けるmax(B,C)以上の最小の位置からB引いてチェック

*/
