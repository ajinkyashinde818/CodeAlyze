import sys

n, k = map(int, input().split())
A = list(map(int, input().split()))

visit = [-1] * n   #到達しているかどうかを管理

D = [1]  # 循環するもののindexを格納

tmp = A[0]  #初期位置
ct = 1

while visit[tmp - 1] == -1:
    D.append(tmp)
    visit[tmp - 1] = ct  #到達済に変更
    if k == ct:
        print(tmp)
        sys.exit()
    ct += 1
    tmp = A[tmp - 1]

#循環している場合の残りの処理
k -= visit[tmp - 1]
k %= (ct - visit[tmp - 1])
print(D[visit[tmp - 1] + k])
