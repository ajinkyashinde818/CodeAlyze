import sys
input = sys.stdin.readline

(k, n), s = map(int, input().split()), sorted(list(map(int, input().split())))
print(k - sorted([s[i] - s[i - 1] for i in range(1, n)] + [k - s[-1] + s[0]])[-1])
