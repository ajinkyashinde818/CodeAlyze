#include <stdio.h>

char board[305][305];
int color[305][305];
int H, W, K;

int current_color;

int main()
{
	scanf("%d %d %d", &H, &W, &K);

	for (int i = 0; i < H; ++i)
	{
		scanf("%s", board[i]);

		bool met = false;

		for (int j = 0; board[i][j]; ++j)
		{
			if (board[i][j] == '#') color[i][j] = ++current_color;
		}
	}

	for (int i = 0; i < H;++i)
	{
		for (int j = 1; board[i][j]; ++j)
		{
			if (!color[i][j] && color[i][j - 1]) color[i][j] = color[i][j - 1];
		}
	}

	for (int i = 0; i < H; ++i)
	{
		for (int j = W - 2; j >= 0; --j)
		{
			if (!color[i][j] && color[i][j + 1]) color[i][j] = color[i][j + 1];
		}
	}

	for (int i = 1; i < H; ++i)
	{
		for (int j = 0; board[i][j]; ++j)
		{
			if (!color[i][j] && color[i - 1][j]) color[i][j] = color[i - 1][j];
		}
	}

	for (int i = H - 2; i >= 0; --i)
	{
		for (int j = 0; board[i][j]; ++j)
		{
			if (!color[i][j] && color[i + 1][j]) color[i][j] = color[i + 1][j];
		}
	}

	for (int i = 0; i < H; ++i)
	{
		for (int j = 0; j < W; ++j) printf("%d ", color[i][j]);
		printf("\n");
	}

	return 0;
}
