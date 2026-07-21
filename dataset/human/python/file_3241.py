from collections import defaultdict

D = defaultdict(int)
N = int(input())

a = 2
while a * a <= N:
    if N % a:
        a += 1
    else:
        N //= a
        D[a] += 1

if N != 1:
    D[N] += 1

ans = 0
for k,v in D.items():
    i = 0
    while i*(i+1) <= v * 2:
        i += 1
    ans += i-1

print(ans)
