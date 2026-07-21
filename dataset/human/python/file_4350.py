def prime_factorization(N):
    tmp = N
    ans = []
    for i in range(2, int(N ** 0.5) + 1):
        count = 0
        while tmp % i == 0:
            tmp //= i
            count += 1
        if count != 0:
            ans.append([i, count])
    if tmp != 1:
        ans.append([tmp, 1])
    if ans == []:
        ans.append([N, 1])
    return ans

def GetLimit(x):
    X = 2*x
    n = 1
    while True:
        if n*(n+1) <= 2 * x < (n+1)*(n+2):
            return n
        n += 1
N = int(input())
if N==1:
    print(0)
    exit()
PrimeList = prime_factorization(N)
ans = 0
for a, b in PrimeList:
    ans += GetLimit(b)
print(ans)
