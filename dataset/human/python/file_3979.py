N = int(input())

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

def step(n):
    s = 1
    ret = 0
    while n >= s:
        n -= s
        s += 1
        ret += 1
    return ret
if N == 1:
    print(0)
    exit()

factor = factorization(N)
ret = 0
for f, g in factor:
    ret += step(g)
print(ret)
