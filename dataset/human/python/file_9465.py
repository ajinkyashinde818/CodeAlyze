n, k = map(int,input().split())
f = [int(x)-1 for x in input().split()]

def tortoise_and_hare(s,f):
    tortoise = f[s]
    hare = f[f[s]]

    while tortoise != hare:
        tortoise = f[tortoise]
        hare = f[f[hare]]

    rho = 0
    tortoise = s
    while tortoise != hare:
        tortoise = f[tortoise]
        hare = f[hare]
        rho += 1

    lamb = 1
    hare = f[hare]

    while tortoise != hare:
        hare = f[hare]
        lamb += 1

    return rho,lamb

rho, lamb = tortoise_and_hare(0,f)

if k <= rho:
    s = 0
    for i in range(k):
        s = f[s]
else:
    s = 0
    for i in range(rho):
        s = f[s]
    k = (k-rho)%lamb
    for i in range(k):
        s = f[s]

print(s+1)
