from math import sqrt
itl = lambda: list(map(float, input().strip().split()))


def solve():
    N = int(input())
    if N == 1:
        return 0

    ans = 0
    for i in range(2, int(sqrt(N)) + 1):
        nxt = 1
        count = 0
        while N % i == 0:
            N //= i
            count += 1
            if count == nxt:
                count = 0
                ans += 1
                nxt += 1
    if N > int(sqrt(N)):
        ans += 1        
    return ans

 
if __name__ == '__main__':
    print(solve())
