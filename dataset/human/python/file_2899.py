from itertools import accumulate
A = [a for a in range(1,41)]
A = list(accumulate(A))

def factorization(n):
    arr = []
    temp = n
    for i in range(2, int(n**0.5//1)+1):
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
n = factorization(N)
cnt = 0
if N == 1:
    print(0)
else:
    for x in n:
        i = 0
        while x[1] >= A[i]:
            cnt += 1
            i += 1
    print(cnt)
