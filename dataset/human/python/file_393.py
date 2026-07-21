def main():
    import sys
    from fractions import gcd
    input = sys.stdin.readline
    N = int(input())
    A = list(map(int, input().split()))
    tmp = float("inf")
    S = 0
    count = 0
    for i in A:
        if tmp > abs(i):
            tmp = abs(i)
        if abs(i) != i:
            count += 1
        S += abs(i)
    if count%2 == 0:
        print(S)
    else:
        print(S-2*tmp)
    
main()
