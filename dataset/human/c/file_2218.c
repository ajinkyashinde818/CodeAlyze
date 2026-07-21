#include <stdio.h>
int main(void)
{
  char s[500001], c, ans[300001];
  int q, t, f, i, j, left_end, right_end, rightward_flg;

  scanf("%s", &s[200000]);            // 標準入力からの値取得
  scanf("%d", &q);                    // 標準入力からの値取得

  rightward_flg = 1;
  left_end = 199999;
  for (right_end = 200000; s[right_end] != '\0'; right_end++)
    ;
  
  for (i = 0; i < q; i++) {
    scanf("%d", &t);                  // 標準入力からの値取得
    if (t == 1) {
      rightward_flg = ~rightward_flg;
    } else {
      scanf("%d %c", &f, &c);         // 標準入力からの値取得
      if (f == 1) {
        if (rightward_flg == 1) {
          s[left_end--] = c;
        } else {
          s[right_end++] = c;
        }
      } else {
        if (rightward_flg == 1) {
          s[right_end++] = c;
        } else {
          s[left_end--] = c;
        }
      }
    }
  }

  // 出力
  if (rightward_flg == 1) {
    s[right_end] = '\0';
    printf("%s\n", &s[++left_end]);
  } else {
    for (i = --right_end, j = 0; i > left_end; i--) {
      ans[j++] = s[i];
    }
    ans[j] = '\0';
    printf("%s\n", ans);
  }
  return 0;
}
