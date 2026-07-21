import sys
input = sys.stdin.readline

n = int(input())
x = list(map(int, input().split()))
mc = 0
m = 1000000001

for v in range(n):
    t = x[v]
    if t < 0:
        mc += 1
    
    m = min(m, abs(t))

if mc % 2 == 0:
    s = 0
    for v in range(n):
        s += abs(x[v])
    print(s)
else:
    s = 0
    for v in range(n):
        t = abs(x[v])
        if t == m:
            s -= t
        else:
            s += t
            
    print(s)
