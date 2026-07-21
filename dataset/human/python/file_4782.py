import sys

stdin = sys.stdin

ni = lambda: int(stdin.readline())
na = lambda: list(map(int, stdin.readline().split()))
ns = lambda: stdin.readline().strip()


s = ns()
t = ns()
s = ''.join(sorted(s))
t = ''.join(sorted(t, reverse=True))
if s < t:
    print('Yes')
else:
    print('No')
