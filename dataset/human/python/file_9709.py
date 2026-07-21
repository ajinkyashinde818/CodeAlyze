from sys import stdin
import sys

N, K = [int(x) for x in stdin.readline().rstrip().split()]
A = list(map(int, input().split()))
B = [i for i in range(1, N+1)]
d = dict(zip(B, A))
t = [0 for i in range(N)]
d1 = dict(zip(B, t))
temp = 1
cnt = 0
ans = []
for i in range(K):
    d1[d[temp]] = d1.get(d[temp], 0)+1
    if d1.get(d[temp], 0) == 2:
        cnt += 1
        ans.append(d[temp])
        # print(i, d[temp])
    if d1.get(d[temp], 0) == 3:
        break
    temp = d[temp]
    if i == K-1:
        print(temp)
        sys.exit()
cnt1 = 0
for i, v in enumerate(d1):
    if d1[v] == 1:
        cnt1 += 1
# print(cnt, cnt1, d1, temp, ans)
k = K-1-cnt1
print(ans[k % cnt])
