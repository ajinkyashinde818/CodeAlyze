import sys
readline = sys.stdin.buffer.readline
sys.setrecursionlimit(10 ** 8)
INF = float('inf')
MOD = 10 ** 9 + 7

def main():
    R, G, B, N = map(int, readline().split())
    ans = 0
    for r in range(3001):
        if R*r>N:
            break
        for g in range(3001):
            b = N - R*r - G*g
            if b<0:
                break
            if b%B==0:
                ans += 1
    print(ans)

if __name__ == '__main__':
    main()
