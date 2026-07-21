import sys

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

if N == 1:
    print(0)
    sys.exit()

f = factorization(N)

result = 0
for p, e in f:
    i = 1
    while True:
        e -= i
        if e < 0:
            break
        result += 1
        i += 1

print(result)
