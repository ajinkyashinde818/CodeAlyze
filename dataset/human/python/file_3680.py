from itertools import groupby

def fact(n):
    table = []
    i = 2
    
    while(i*i <= n):
        while(n%i == 0):
            n //=i
            table.append(i)
        i += 1
    if(n > 1):
        table.append(n)
    return table

def main():
    N = int(input())
    P = fact(N)
    ans = 0
    for v, g in groupby(P):
        n = len(list(g))
        for i in range(1, 100000):
            n -= i
            if(n >= 0):
                ans += 1
            else:
                break
    print(ans)
    
main()
