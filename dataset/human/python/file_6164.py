import sys
stdin = sys.stdin
read_int = lambda : list(map(int,stdin.readline().split()))
read_str = lambda : stdin.readline().rstrip()

A, B, C = read_int()

Detoxification = C - B - A

res = B + C if Detoxification <= 0 else 2*B + A + 1
print(res)
