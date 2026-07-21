n = int(input())

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

ans = 0
ch = 0
tmp = 0
if n == 1:
    print(0)
    exit()

for fn in factorization(n):
    while True:
        ch += 1
        if fn[1] >= ch:
            fn[1] -= ch
            tmp += 1
        else:
            break
    ans += tmp
    tmp = 0
    ch = 0
print(ans)
