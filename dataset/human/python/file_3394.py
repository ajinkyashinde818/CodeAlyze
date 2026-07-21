import numpy as np
import sys

N = int(input())
if N == 1:
    print(0)
    sys.exit()

d = int(N ** .5)

def eratosthenes(N):
	is_prime = [True] * (N + 1)
	is_prime[0], is_prime[1] = False, False
	for i in range(2, int(N**(1/2)) + 1):
		if is_prime[i]:
			for j in range(i * 2, N + 1, i):
				is_prime[j] = False
	return [i for i in range(N+1) if is_prime[i]]

p_num = eratosthenes(d+1)
MAX_p = p_num[-1]
ans = 0
used = []
for p in p_num:
    t_p = p
    while N % p == 0:
        N //= p
        ans += 1
        p *= t_p
    while N % t_p == 0:
        N //= t_p

if N > MAX_p:
    dd = int(N ** .5)
    cond = 1
    for i in range(2, dd+1):
        if N % i == 0:
            cond = 0
            break
    if cond:
        ans += 1
    
print(ans)
