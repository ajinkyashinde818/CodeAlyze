import sys
import random
sys.setrecursionlimit(200000)
input = sys.stdin.readline

K, S = map(int, input().split())

ans = 0
for i in range(K + 1):
    for j in range(K + 1):
        t = S - i - j
        if 0 <= t and t <= K:
            ans += 1

print(ans)
