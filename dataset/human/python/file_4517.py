n = int(input())
ans = 0

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

def cnt(n):
    count = 1
    while n>=count:
        n -= count
        count+=1
    return count-1

if n==1:
    print(0)
    exit()

lst = factorization(n)
for i in lst:
    ans += cnt(i[1])

print(ans)
