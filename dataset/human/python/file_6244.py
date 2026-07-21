import sys

stdin = sys.stdin

ns = lambda: stdin.readline().rstrip()
ni = lambda: int(stdin.readline().rstrip())
nm = lambda: map(int, stdin.readline().split())
nl = lambda: list(map(int, stdin.readline().split()))

s = list(map(int, list(input())))[::-1] + [0]*2
n = len(s) - 1
cnt = 0
fl = 0
for i in range(n+1):
    if s[i] > 5 or (s[i] == 5 and s[i+1] >= 5):
        cnt += 10 - s[i]
        s[i+1] += 1
    else:
        cnt += s[i]

print(cnt)
