import sys, math
input = sys.stdin.readline
rs = lambda: input().strip()
ri = lambda: int(input())
rl = lambda: list(map(int, input().split()))
mod = 10**9 + 7

N = ri()

def get_divisors(n):
    divs = []
    for i in range(2, int(n**0.5)+1):
        c = 0
        while n % i == 0:
            n = n // i
            c += 1
        if c > 0:
            divs.append((i, c))
    if n > 1:
        divs.append((n, 1))
    return divs

divs = get_divisors(N)

ans = 0
for p, c in divs:
	i = 1
	while c >= i:
		c -= i
		ans += 1
		i += 1

print(ans)
