import sys
N = int(input())
if N == 1:
    print(0)
    sys.exit(0)
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
L = factorization(N)
ans = []
for case in L:
    p = case[0]
    k = case[1]
    for i in range(1,k+1):
        ans.append(p**i)
ans.sort()
used = []
for el in ans:
    if el not in used and N % el == 0:
        N /= el
        used.append(el)
print(len(used))
sys.exit(0)
