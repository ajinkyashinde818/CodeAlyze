N = int(input())

def f(n):
    if n < 2:
        return 1
    return n * f(n - 2)

def zeros(n):
    count = 0
    cur = n
    while(cur != 0 and cur % 10 == 0):
        cur = cur // 10
        count += 1
    return count

def est(n):
    ev = n // 10
    divider = 50
    while(n // divider != 0):
        ev += n // divider
        divider *= 5
    return ev

if N % 2 == 1:
    print(0)
else:
    print(est(N))
