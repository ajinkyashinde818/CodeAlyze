def main():
    import sys
    input = sys.stdin.readline
    from collections import defaultdict
    N = int(input())
    ans = defaultdict(int)
    while N % 2 == 0:
        ans[2] += 1
        N //= 2
    f = 3
    while f * f <= N:
        if N % f == 0:
            ans[f] += 1
            N //= f
        else:
            f += 2
    if N != 1:
        ans[N] += 1
    
    Ans = 0
    for v in ans.values():
        x = 1
        while x * (x+1) // 2 <= v:
            x += 1
        Ans += x-1
    print(Ans)

if __name__ == '__main__':
    main()
