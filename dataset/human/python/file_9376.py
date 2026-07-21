import numpy as np

N, K = map(int, input().split())

A = np.zeros((N), dtype=np.int)
*A[:], = map(int, input().split())
A[:] -= 1 # 0ベースに変更

visited = np.zeros((N), dtype=np.bool)
recent_turn = np.zeros((N), dtype=np.int64)

here = 0
rest_turn = K

while rest_turn > 0:
	if visited[here]:
		# 周回スキップ実装
		interval = recent_turn[here] - rest_turn
		rest_turn %= interval
		if rest_turn == 0:
			break
	else:
		# ソシャゲ周回
		visited[here] = True
	
	recent_turn[here] = rest_turn
	here = A[here]
	rest_turn -= 1

# 1ベースに戻す
print(here + 1)
