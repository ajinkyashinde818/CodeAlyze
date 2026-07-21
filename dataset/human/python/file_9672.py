import sys
n, k = map(int, input().split())
a = list(map(int, input().split()))

a = [_ - 1 for _ in a]

history = []
last_visited = [None for i in range(n)]
now = 0

history.append(0)
last_visited[0] = 0

for t in range(1, k+1): # 1, 2, ..., k
  now = a[now]
  history.append(now)
  
  if last_visited[now] is None:
    last_visited[now] = t
    if t == k:
      print(now + 1)
      sys.exit()
  else:
    t0 = last_visited[now]
    t1 = t
    # 頂点 now に t0 及び t1 に訪問した状況
    # 等差数列 S = [t0, t1, .....] を考えて，
    # 「k 以下の最大の S の要素」t_max を求める
    t_max_idx = (k - t0) // (t1 - t0)
    t_max = t0 + (t1 - t0) * t_max_idx
    
    # 時刻 t_max に history[t0] にいる
    # → 時刻 k には history[t0 + (k - t_max)] にいる
    print(history[t0 + (k - t_max)] + 1)
    sys.exit()
