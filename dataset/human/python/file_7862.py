from collections import defaultdict

N ,K,S = list(map(int,input().split(" ")))

ans = []
for _ in range(K):
    ans.append(S)
if S == 1:
    hoge = 2
else:
    hoge = S//2 + 1
for _ in range(N - K):
    ans.append(hoge)
print(*ans)
