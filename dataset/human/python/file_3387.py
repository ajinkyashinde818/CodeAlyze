from collections import Counter
def soinsu(n, lists):
    for i in range(2, int(n ** 0.5) + 1):
        if n % i == 0:
            return soinsu(n // i, lists + [i])
    return lists + [n]
    
    
N = int(input())
if N == 1:
    print(0)
    exit()

a = soinsu(N, [])
ans = 0
    
tmp = Counter(a)

for i in tmp.values():
    s = 1
    counts = 1
    while True:
        counts += 1
        if i >= s:
            ans += 1
            s += counts
        else:
            break

print(ans)
