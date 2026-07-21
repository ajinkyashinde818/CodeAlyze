from collections import defaultdict, deque, Counter
def inpl(): return list(map(int, input().split()))

R, G, B, N = inpl()
ans = 0
for r in range(N//R + 1):
    for g in range(N//G + 1):
        tmp = N - R*r - G*g
        if tmp < 0:
            break
        if (tmp%B == 0):
            ans += 1
print(ans)
