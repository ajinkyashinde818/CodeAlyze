import math
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

def resolve():
    N = int(input())
    if N == 1:
        print(0)
    else:
        N_fact = factorization(N)
        ans = 0
        for i in range(len(N_fact)):
            Ni =  N_fact[i][1]
            ans = ans + int((-1 + math.sqrt(1 + 8 * Ni)) / 2)
        print(ans)
resolve()
