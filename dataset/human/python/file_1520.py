import sys
read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines
sys.setrecursionlimit(10 ** 7)

n, m = map(int, readline().split())
a = [readline().rstrip().decode() for _ in range(n)]
b = [readline().rstrip().decode() for _ in range(m)]
print('Yes' if any([aa[x:x + m] for aa in a[y:y + m]] == b for y in range(n - m + 1) for x in range(n - m + 1)) else 'No')
