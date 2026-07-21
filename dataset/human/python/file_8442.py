import sys

stdin = sys.stdin

ns = lambda: stdin.readline().rstrip()
ni = lambda: int(stdin.readline().rstrip())
nm = lambda: map(int, stdin.readline().split())
nl = lambda: list(map(int, stdin.readline().split()))

k,n = nm()
a = nl()
a.append(a[0] + k)
print(k - max(a[i+1] - a[i] for i in range(n)))
