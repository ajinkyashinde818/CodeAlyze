import sys

def main():
    input = sys.stdin.readline
    N = int(input())
    S = [str(c) for c in input().strip()]

    ans = 0
    d = {}
    for i in range(N-1, -1, -1):
        s = S[i]
        if s in d:
            d[s] += 1
        else:
            d[s] = 1

        t = 1
        for k in d:
            if k == s:
                continue

            t *= d[k] + 1

        ans += t
    
    print(ans % (10**9 + 7))


if __name__ == '__main__':
    main()
