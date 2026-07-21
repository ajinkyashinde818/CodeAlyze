import sys
def input(): return sys.stdin.readline().strip()

def resolve():
    n=int(input())
    def prime_factorize1(N):
        l = []
        x = N
        y = 2
        while y*y <= x:
            while x % y == 0:
                l.append(y)
                x //= y
            y += 1
        if x > 1:
            l.append(x)
        return l

    from collections import Counter
    c=Counter(prime_factorize1(n))
    num=list(c.values())
    ans=0
    for i in num:
        x=i
        for j in range(1,i+1):
            if x-j>=0:
                ans+=1
                x-=j
            else:
                break
    print(ans)
resolve()
