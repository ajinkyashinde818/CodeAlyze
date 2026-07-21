import sys
import collections

sys.setrecursionlimit(10 ** 8)

input = sys.stdin.readline


def main():
    S = input().strip()

    if S == S[::-1]:
        print(0)
        return

    S2 = [s for s in S if s != 'x']

    if S2 == S2[::-1]:
        ans = 0
        l = 0
        r = len(S) - 1
        while l < r:
            if S[l] == S[r]:
                l += 1
                r -= 1
                continue
            else:
                if S[l] == 'x':
                    ans += 1
                    l += 1
                else:
                    ans += 1
                    r -= 1
        print(ans)
    else:
        print(-1)

    

if __name__ == '__main__':
    main()
