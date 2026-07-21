import sys
read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines
sys.setrecursionlimit(10 ** 7)

n, *a = map(int, read().split())
cnt = 0
for i, aa in enumerate(a):
    if aa < 0:
        a[i] = -aa
        cnt += 1
if cnt % 2 == 0:
    print(sum(a))
else:
    print(sum(a) - min(a) * 2)
