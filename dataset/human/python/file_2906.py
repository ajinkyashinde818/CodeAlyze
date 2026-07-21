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
ans = 0
det = []
if N ==1:
    ans = 0
else:
    for (i, j) in factorization(N):
        max_x = pow(i, j)
        #print(max_x)
        v = i
        temp = 1
        for k in range(j):
            x = pow(v, k+1)
            #print(x)
            if x not in det and temp*x <= max_x:
                temp *= x
                ans += 1
                det.append(x)
    #print("")
print(ans)
