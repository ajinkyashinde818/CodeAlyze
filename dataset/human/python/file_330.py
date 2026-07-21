import sys, os

f = lambda:list(map(int,input().split()))
if 'local' in os.environ :
    sys.stdin = open('./input.txt', 'r')

def solve():
    n = f()[0]
    a = f()

    cntp = 0
    cntn = 0
    cnt0 = 0

    total = 0
    miabs = int(1e10)
    for i in range(n):
        total += abs(a[i])
        miabs = min(miabs, abs(a[i]))
        if a[i]>0:
            cntp += 1
        elif a[i] < 0:
            cntn += 1
        else:
            cnt0 += 1
    

    if cntn%2 == 0 or cnt0 > 0:
        print(total)
    else:
        print(total - 2*miabs)


solve()
