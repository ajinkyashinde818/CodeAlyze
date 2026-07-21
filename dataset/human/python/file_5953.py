import sys

[N] = [int(x) for x in sys.stdin.readline().split(" ")]

As = [int(x) - 1 for x in sys.stdin.readline().split(" ")]
Bs = [int(x) for x in sys.stdin.readline().split(" ")]
Cs = [int(x) for x in sys.stdin.readline().split(" ")]

prev = -999
result = 0
for i in range(N):
    a = As[i]
    result += Bs[a]
    if a == prev+1:
        result += Cs[prev]
    prev = a

print(result)
