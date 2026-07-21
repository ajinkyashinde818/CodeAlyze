import sys
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

n = int(input())

if n == 1:
    print(0)
    sys.exit()

ar = factorization(n) 
ar_len = len(ar)
ans = 0
for i in range(ar_len):
    jo = ar[i][1]
    ad = 0
    for j in range(1000):
        base = j*(j+1)/2
        if jo < base:
            ad = j-1
            break
    ans = ans + ad

print(ans)
