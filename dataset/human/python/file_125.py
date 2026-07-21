def main():
    a,b,c,n=map(int,input().split())
    res = 0
    l = [a,b,c]
    l.sort()
    for i in range(n // l[2]+1):
        for j in range(n//l[1]+1):
            if n < l[2]*i+l[1]*j:
                break
            if (n - l[2] * i - l[1] * j ) % l[0] == 0:
                res += 1
    print(res)

main()
