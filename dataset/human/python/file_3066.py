n = int(input())

if n == 1:
    print(0)
    exit()

def factorization(n):
    seq = []
    temp = n
    for i in range(2, int(-(-n**0.5//1))+1):
        if temp%i==0:
            cnt=0
            while temp%i==0:
                cnt+=1
                temp //= i
            seq.append([i, cnt])

    if temp!=1:
        seq.append([temp, 1])

    if seq==[]:
        seq.append([n, 1])

    return seq

so = factorization(n)

ans = 0
for i in range(len(so)):
    j = 1
    mun = so[i][1]
    while mun >= j:
        if mun - j >= 0:
            ans += 1
            mun -= j
            j += 1

print(ans)
