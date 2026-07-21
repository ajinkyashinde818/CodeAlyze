import math
from collections import defaultdict
def prime_decomposition(n):
    i = 2
    table = []
    while i * i <= n:
        while n % i == 0:
          n /= i
          table.append(i)
        i += 1
    if n > 1:
        table.append(n)
    return table
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
def main():
    dd = defaultdict(int)
    n = int(input())
    pri = factorization(n)
    res = 0
    i  = len(pri)-1
    ans = 0

    for i in pri:
        k = i[1]
        i=1
        tmp=2
        cnt = 0
        while i<=k:
            i+=tmp
            tmp+=1
            cnt+=1
        ans+=cnt
    if len(pri)==1 and pri[0][1]==1:
        ans=1
    if n==1:
        ans = 0
    print(ans)


if __name__ == '__main__':
    main()
