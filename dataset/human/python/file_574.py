def solve():
    N = int(input())
    A = list(map(int,input().split()))
    minus = len([a for a in A if a < 0])
    zero = len([a for a in A if a == 0])
    absA = [abs(a) for a in A]
    low = sorted(absA)[0]
    if minus % 2 == 0:
        return sum(absA)
    elif zero >= 1:
        return sum(absA)
    return sum(absA) - low * 2

print(solve())
