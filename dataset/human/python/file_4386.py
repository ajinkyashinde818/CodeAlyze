n = int(input())

def factorization(n):
    arr = []
    temp = n
    for i in range(2, int(-(-n**0.5//1))+1):
        if temp%i==0:
            cnt=0
            while temp%i==0:
                cnt+=1
                temp //= i
            arr.append(cnt)

    if temp!=1:
        arr.append(1)

    if arr==[]:
        arr.append(1)

    return arr

A = []
t = 0
for i in range(50):
    t += i
    A.append(t)
import bisect

B = factorization(n)
total = 0

for i in B:
    if i == A[bisect.bisect(A, i)]:
        total += bisect.bisect(A, i)
    else:
        total += bisect.bisect(A, i)-1
if n == 1:
    print(0)
else:
    print(total)
