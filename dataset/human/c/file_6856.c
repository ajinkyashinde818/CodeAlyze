#include <stdio.h>
#include <string.h>
#include <limits.h>

int subsum[101][101];

int main(void)
{
  int n, x, y, x1, y1, x2, y2;
  int max = INT_MIN;  /* 最大値を覚えておく変数 */

  /* 配列データの初期化 */
  memset(subsum,0,sizeof(subsum));

  /* 入力データの読み込み */
  scanf("%d", &n);
  for(y=1; y<=n; y++){
	for(x=1; x<=n; x++){
	  int m;
	  scanf("%d", &m);
	  subsum[y][x] = m + subsum[y-1][x] + subsum[y][x-1] - subsum[y-1][x-1];
	}
  }

  /* 部分行列を全探索 */
  for(y1=0; y1<n; y1++){
	for(x1=0; x1<n; x1++){
	  for(y2=y1+1; y2<=n; y2++){
		for(x2=x1+1; x2<=n; x2++){
		  int s = subsum[y2][x2] - subsum[y1][x2] - subsum[y2][x1] + subsum[y1][x1];
		  if(max < s) max = s;
		}
	  }
	}
  }

  /* 答えを表示 */
  printf("%d\n", max);

  return 0;
}
