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

import sys
N = int(input())
if N == 1:
    print(0)
    sys.exit()
A = factorization(N)
ans = 0
for i in range(len(A)):
    for j in range(1,A[i][1]+1):
        if N % A[i][0]**j == 0:
            ans += 1
            N //= A[i][0]**j
        else:
            break

print(ans)
