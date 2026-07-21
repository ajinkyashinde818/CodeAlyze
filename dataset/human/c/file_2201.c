#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define POW_10_5 100100
#define MAX_INPUTSTR_LEN POW_10_5 // 読み込む文字列の長さの最大値
#define MAX_Q_LEN (2 * POW_10_5) // Q の最大値

// #define GBN6500_DEBUG

char *buffer, *prevPtr, *postPtr;
int Q;
bool isReversed; // 反転状態なら true

void InvertString(char *str)
{
    int len = strlen(str);
    char *tmp = (char *)malloc(len + 10);
    for (int i = 0; i < len; ++i)
        tmp[i] = str[len - i - 1];
    tmp[len] = '\0';
    strcpy(str, tmp);
    free(tmp); 
}

void Solve()
{
  int T, F;
  char C;
  for (int i = 0; i < Q; ++i){
    scanf("%d", &T);
    if (T == 1){
      isReversed = !isReversed;
    } else {
      scanf("%d %c", &F, &C);
      if (F == 1)
        if (!isReversed) *prevPtr = C, --prevPtr; // 一文で書けると思うけどよくわからないのでカンマで誤魔化した
        else *postPtr = C, ++postPtr;
      else
        if (!isReversed) *postPtr = C, ++postPtr;
        else *prevPtr = C, --prevPtr;
      }

#ifdef GBN6500_DEBUG
printf("i = %d, type = %d, isReversed = %d, ans = [%s]\n", i, T, isReversed, prevPtr + 1);
#endif

  } // end for
  *postPtr = '\0';
  char *ans = (char *)(prevPtr + 1);

  if (isReversed) InvertString(ans);

  puts(ans);
}

void Init()
{
#define ALLOC_MEM_SIZE (MAX_Q_LEN + MAX_INPUTSTR_LEN + MAX_Q_LEN)
  // 制約の最大値（＋α）でヒープにメモリーを確保
  // これだけ確保しても約 800KB なので、メモリー制限にはひっかからない（と思う）
  buffer = (char *)malloc(ALLOC_MEM_SIZE);
#ifdef GBN6500_DEBUG
memset(buffer, 0, ALLOC_MEM_SIZE); // 46行目の printfデバッグ用
#endif

  isReversed = false;

  scanf("%s %d", buffer, &Q);
  prevPtr = buffer + MAX_Q_LEN;
  postPtr = prevPtr + strlen(buffer) + 1;
  strcpy(prevPtr + 1, buffer); // buffer の前に MAX_Q ぶんのスペースを開ける。文字を前に追加する時はこのスペースを利用。
}

void Clean()
{
  free(buffer);
}

int main(){ Init(); Solve(); Clean(); return 0; }
