"""nを素因数分解"""
"""2以上の整数n => [[素因数, 指数], ...]の2次元リスト"""

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

N = int(input())

if(N == 1):
    print(0)
    exit()

fact = factorization(N)

ans = 0

for _,i in fact:
    cnt = 0
    j = 0
    while(True):
        if(cnt + j + 1 > i ):
            ans += j
            break
        j += 1
        cnt += j 
        
print(ans)
