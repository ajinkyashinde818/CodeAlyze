def solve():
    n = int(input())
    a = list(map(int, input().split()))

    one = n*(n+1)/2

    if sum(a) % one != 0:
        print("NO")
        return
    else:
        nop = sum(a) / one

    d = [0 for i in range(n)]
    for i in range(n):
        d[i] = a[(i+1)%n] - a[i]
        d[i] = d[i] - nop

    count = 0

    for i in range(n):
        if d[i] != 0:
            if d[i] % n != 0 or d[i] > 0:
                print("NO")
                return
            count = count + (-1*d[i]) / n
            d[i] = 0
            if count > nop:
                print("NO")
                return

    if sum(d) == 0 and count == nop:
        print("YES")
    else:
        print("NO")

solve()
