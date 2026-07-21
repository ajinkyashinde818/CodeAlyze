import math

def isprime(n):
    for k in range(2,math.floor(math.sqrt(n))+1):
        if n%k == 0:
            return False
    return True

N = int(input())
if N == 1:
    print(0)
    exit(0)

P = [N]
for k in range(2,math.floor(math.sqrt(N))+1):
    if N % k == 0:
        P.append(k)
        P.append(N//k)
P = sorted(P)
Q = []
for k in range(len(P)):
    if isprime(P[k]) == True:
        temp = 0
        while N%P[k] == 0:
            N //= P[k]
            temp += 1
        Q.append(temp)

ans = 0
for e in Q:
    if e > 0:
        t = 0
        for k in range(1,100):
            t += k
            if t <= e:
                ans += 1
            else:
                break
print(ans)
