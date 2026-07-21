from collections import Counter
from bisect import bisect_right

def prime_decompose(x):
    decomposed = []
    for i in range(2,int(pow(x,0.5))+1):
        while x % i == 0:
            x //= i
            decomposed.append(i)
    if x > 1:
        decomposed.append(x)
    return decomposed

N = int(input())
d = prime_decompose(N)
cnt = Counter(d)
ref = [0] * 50
for i in range(len(ref)):
    ref[i] = sum(range(1,i+2))

ans = 0
for i in cnt:
    ans += bisect_right(ref, cnt[i])

print(ans)
