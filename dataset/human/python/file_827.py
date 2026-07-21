import sys
read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines
sys.setrecursionlimit(500000)

N, R = list(map(int, read().split()))

if N >= 10:
    print(R)
else:
    print(R + 100 * (10 - N))
