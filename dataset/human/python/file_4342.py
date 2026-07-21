import collections,sys
def I(): return int(sys.stdin.readline().rstrip())
N = I()
def primeFactor(num):
    prime_factor = collections.defaultdict(int)
    for i in range(2,int(num**0.5)+1):
        while num%i==0:
            prime_factor[i] += 1
            num //= i
    if num>1:
        prime_factor[num]=1
    return prime_factor
sequence = []
for i in range(1,50):
    sequence.append(i*(i+1)//2)
ans = 0
for v in primeFactor(N).values():
    for j,x in enumerate(sequence,1):
        if v<x:
            ans += j-1
            break
print(ans)
