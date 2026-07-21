def factorization(n):
    if n==1:
        return []
    arr = []
    temp = n
    cand = [2]+list(range(3, int(-(-n**0.5//1))+1, 2))
    for i in cand:
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

max_N=1000
s = [i for i in range(1, max_N)]
sums = [sum(s[:i]) for i in range(1,max_N)]
def comb(a):
    for i in range(max_N):
        if a<sums[i]:
            return i

N = int(input())
fac = factorization(N) 
res = 0
for a in [el[1] for el in fac]:
    res += comb(a)
print(res)
