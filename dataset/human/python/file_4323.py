def factorization(n):
    arr = []
    temp = n
    for i in range(2, int(-(-n**0.5//1))+1):
        if temp%i==0:
            cnt=0
            while temp%i==0:
                cnt+=1
                temp //= i
            arr.append([i, cnt])

    if temp!=1:
        arr.append([temp, 1])

    if arr==[]:
        arr.append([n, 1])

    return arr

N = int(input())
used = list()
count = 0
while N > 1:
    operated = False
    factor = factorization(N)
    candidate = list()
    for f in factor:
        base = f[0]
        for e in range(1, f[1]+1):
            candidate.append(pow(base, e))
    candidate.sort()

    for z in candidate:
        if z in used or N % z != 0:
            continue
        count += 1
        operated = True
        used.append(z)
        N //= z

    if not operated:
        break

print(count)
