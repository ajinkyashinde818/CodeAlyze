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

n = int(input())
ln = factorization(n)
ans = 0
for i in range(1, max(ln) + 1):

    ln = [x for x in ln if x >= i]
    ans += len(ln)
    ln = list(map(lambda x: x - i, ln))
    if sum(ln)==0:
        break
import sys

if n == 1:
    print(0)
    sys.exit()
print(ans)
